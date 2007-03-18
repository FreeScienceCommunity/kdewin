import sys
import os

import shutil

# for get functions etc...
import utils

ROOTDIR=os.getenv( "KDEROOT" )
print "KDEROOT:", ROOTDIR

COMPILER=os.getenv( "KDECOMPILER" )
print "KDECOMPILER:", COMPILER

DOWNLOADDIR=os.path.join( ROOTDIR, "distfiles" )

# ok, we have the following dirs:
# ROOTDIR: the root where all this is below
# DOWNLOADDIR: the dir under rootdir, where the downloaded files are put into
# WORKDIR: the directory, under which the files are unpacked and compiled.
#			here rootdir/tmp/packagename/work
# IMAGEDIR: the directory, under which the compiled files are installed.
#			here rootdir/tmp/packagename/image

	
class baseclass:
	def __init__( self, SRC_URI ):
		#print "base init called"
		self.SRC_URI=SRC_URI
		self.instsrcdir=""
		self.instdestdir=""

	def execute( self ):
		print "base exec called. args:", sys.argv
		#print "fetch url:", self.SRC_URI

		command = sys.argv[ 1 ]
		#print "command:", command

		self.setDirectories()
		
		if COMPILER == "msvc2005":
			self.compiler = "msvc2005"
		elif COMPILER == "mingw":
			self.compiler = "mingw"
		else:
			print "error: KDECOMPILER: %s not understood" % COMPILER
			exit( 1 )

		ok = True
		if command == "fetch":	    ok = self.fetch()
		elif command == "unpack":   ok = self.unpack()
		elif command == "compile":  ok = self.compile()
		elif command == "install":
			# make sure the image dir is clean
			if ( os.path.exists( self.imagedir ) ):
				print "cleaning image dir:", self.imagedir
				utils.cleanDirectory( self.imagedir )
			ok = self.install()
		elif command == "qmerge":   ok = self.qmerge()
		elif command == "merge":
			ok = self.fetch()
			if ( ok ): 	ok = self.unpack()
			if ( ok ):	ok = self.compile()
			if ( os.path.exists( self.imagedir ) ):
				print "cleaning image dir:", self.imagedir
				utils.cleanDirectory( self.imagedir )
			if ( ok ):	ok = self.install()
			if ( ok ):	ok = self.qmerge()
			if ( ok ):
				print "merge success"
		else:
			print "command %s not understood" % command
			ok = False

		if ( not ok ):
			print "an error happened"
			exit( 1 )

	def fetch( self ):
		print "base fetch called"
		return utils.getFiles( self.SRC_URI, self.downloaddir )

	def unpack( self ):
		print "base unpack called, files:", self.filenames
		return utils.unpackFiles( self.downloaddir, self.filenames, self.workdir )

	def compile( self ):
		print "base compile called, doing nothing..."
		return True

	def install( self ):
		print "base install called"
		srcdir = os.path.join( self.workdir, self.instsrcdir )
		destdir = os.path.join( self.imagedir, self.instdestdir )
		utils.copySrcDirToDestDir( srcdir, destdir )
		return True

	def qmerge( self ):
		print "base qmerge called"
		utils.mergeImageDirToRootDir( self.imagedir, self.rootdir )
		utils.addInstalled( self.category, self.package, self.version )
		return True


	def setDirectories( self ):
		print "setdirectories called"
		#print "basename:", sys.argv[ 0 ]
		#print "src_uri", self.SRC_URI

		filenames = []
		for uri in self.SRC_URI.split():
			filenames.append( os.path.basename( uri ) )
		self.filenames = filenames
		#print "filenames:", self.filenames

		#( self.progname, ext ) = os.path.splitext( os.path.basename( sys.argv[ 0 ] ) )
		( self.PV, ext ) = os.path.splitext( os.path.basename( sys.argv[ 0 ] ) )
		#print "progname:", self.progname		

		( self.category, self.package, self.version ) = \
					   utils.getCategoryPackageVersion( sys.argv[ 0 ] )

		#self.progname = self.package		
		#print "setdir category: %s, package: %s, version: %s" %\
		#	  ( self.category, self.package, self.version )

		
		self.cmakeInstallPrefix = ROOTDIR.replace( "\\", "/" )
		print "cmakeInstallPrefix:", self.cmakeInstallPrefix

		self.rootdir     = ROOTDIR
		self.downloaddir = os.path.join( ROOTDIR, "distfiles" )
		self.workdir     = os.path.join( ROOTDIR, "tmp", self.PV, "work" )
		self.imagedir    = os.path.join( ROOTDIR, "tmp", self.PV, "image" )

		self.filesdir = os.path.join( ROOTDIR, "emerge", \
		    "portage", "kde", "kdelibs", "files" )

	def svnFetch( self, repo ):
		print "base svnFetch called"
		self.svndir = os.path.join( self.downloaddir, "svn-src", self.package )
		utils.svnFetch( repo, self.svndir )
		
		
		
		
		