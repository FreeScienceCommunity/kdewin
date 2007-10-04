import base
import utils
import shutil
from utils import die
import os

# FIXME implement shadow build and installation into image dir.

PACKAGE_NAME         = "qt"
PACKAGE_VER          = "4.3.2"
PACKAGE_FULL_VER     = "4.3.2-1"
PACKAGE_FULL_NAME    = "%s-all-opensource-src-%s" % ( PACKAGE_NAME, PACKAGE_VER )

DEPEND = """
dev-util/win32libs
virtual/base
"""

SRC_URI= """
ftp://ftp.trolltech.com/qt/source/""" + PACKAGE_FULL_NAME + """.tar.gz
"""

class subclass(base.baseclass):
  def __init__(self):
    base.baseclass.__init__( self, SRC_URI )
    self.instsrcdir = PACKAGE_FULL_NAME + "-" + self.compiler

  def unpack( self ):
    qtsrcdir = os.path.join( self.workdir, self.instsrcdir )
    qtsrcdir_tmp = os.path.join( self.workdir, PACKAGE_FULL_NAME )

    utils.cleanDirectory( qtsrcdir )
    utils.cleanDirectory( qtsrcdir_tmp )

    if ( not utils.unpackFile( self.downloaddir, self.filenames[0], self.workdir ) ):
      return False
    os.rmdir( qtsrcdir )
    os.rename( qtsrcdir_tmp, qtsrcdir )

    # disable demos and examples
    sedcommand = r""" -e "s:SUBDIRS += examples::" -e "s:SUBDIRS += demos::" """
    utils.sedFile( qtsrcdir, "projects.pro", sedcommand )

    # patch to disable building of pbuilder_pbx.cpp, as it takes ages
    path = os.path.join( qtsrcdir, "qmake" )
    file = "Makefile.win32-g++"
    sedcommand = """ -e "s/pbuilder_pbx.o//" """
    utils.sedFile( path, file, sedcommand )

    # disable usage of it
    path = os.path.join( qtsrcdir, "qmake", "generators" )
    file = "metamakefile.cpp"
    sedcommand = r""" -e "s:^.*ProjectBuilder://\0:" """
    utils.sedFile( path, file, sedcommand )

    # help qt a little bit :)
    cmd = "cd %s && patch -p0 < %s" % \
          ( qtsrcdir, os.path.join( self.packagedir, "qt-4.3.2.diff" ) )
    os.system( cmd ) and die( "qt unpack failed" )
    # and once more... :)  (Issue N180186)
    cmd = "cd %s && patch -p0 < %s" % \
          ( qtsrcdir, os.path.join( self.packagedir, "qmake-mingw.diff" ) )
    os.system( cmd ) and die( "qt unpack failed" )
    # the third one (Issue N180187)
    cmd = "cd %s && patch -p0 < %s" % \
          ( qtsrcdir, os.path.join( self.packagedir, "qdbus-win32-install.diff" ) )
    os.system( cmd ) and die( "qt unpack failed" )
    # more libs to install (Issue N180864)
    cmd = "cd %s && patch -p0 < %s" % \
          ( qtsrcdir, os.path.join( self.packagedir, "qt_install_toollibs.diff" ) )
    os.system( cmd ) and die( "qt unpack failed" )

    return True

  def compile( self ):
    # time for qt4.3.2 ...

    qtsrcdir = os.path.join( self.workdir, self.instsrcdir )
    os.chdir( qtsrcdir )

    # so that the mkspecs can be found, when -prefix is set
    os.putenv( "QMAKEPATH", qtsrcdir )

    if self.traditional:
        win32incdir = os.path.join( self.rootdir, "win32libs", "include" ).replace( "\\", "/" )
        win32libdir = os.path.join( self.rootdir, "win32libs", "lib" ).replace( "\\", "/" )
    else:
        win32incdir = os.path.join( self.rootdir, "include" ).replace( "\\", "/" )
        win32libdir = os.path.join( self.rootdir, "lib" ).replace( "\\", "/" )

    # recommended from README.qt-copy
    #  "configure.exe -prefix ..\..\image\qt -platform win32-g++ " \
    #  "-qt-gif -no-exceptions -debug -system-zlib -system-libpng -system-libmng " \
    #  "-system-libtiff -system-libjpeg -openssl " \
    #  "-I %s -L %s" % ( win32incdir, win32libdir )

    # configure qt
    # prefix = os.path.join( self.rootdir, "qt" ).replace( "\\", "/" )
    prefix = os.path.join( self.imagedir, self.instdestdir )
    platform = ""
    libtmp = os.getenv( "LIB" )
    inctmp = os.getenv( "INCLUDE" )
    if self.compiler == "msvc2005":
        platform = "win32-msvc2005"
    elif self.compiler == "mingw":
        os.environ[ "LIB" ] = ""
        os.environ[ "INCLUDE" ] = ""
        platform = "win32-g++"
    else:
        exit( 1 )

    os.environ[ "USERIN" ] = "y"
    os.chdir( qtsrcdir )
    command = r"echo y | configure.exe -platform %s -prefix %s " \
      "-qdbus -qt-gif -no-exceptions -qt-libpng " \
      "-system-libjpeg -system-libtiff -openssl " \
      "-fast -no-vcp -no-dsp " \
      "-I %s -L %s " % \
      ( platform, prefix, win32incdir, win32libdir )
    print "command: ", command
    os.system( command ) and die( "qt configure failed" )

    # build qt
    os.system( self.cmakeMakeProgramm ) and die( "qt make failed" )

    if( not libtmp == None ):
        os.environ[ "LIB" ] = libtmp
    if( not inctmp == None ):
        os.environ[ "INCLUDE" ] = inctmp
    return True

  def install( self ):
    qtsrcdir = os.path.join( self.workdir, self.instsrcdir )
    os.chdir( qtsrcdir )

    os.system( "%s install" % self.cmakeMakeProgramm ) \
               and die( "qt make install failed" )

    src = os.path.join( self.packagedir, "qt.conf" )
    dst = os.path.join( self.imagedir, self.instdestdir, "bin", "qt.conf" )
    shutil.copy( src, dst )

    return True

  def make_package( self ):
    return self.doPackaging( PACKAGE_NAME, PACKAGE_FULL_VER, False )

subclass().execute()