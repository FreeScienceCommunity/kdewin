TEMPLATE	= lib
TARGET		= kdewin32

include( ../common.pro )

win32-g++: {
	LIBS += -lws2_32 -ladvapi32 -lshell32 
	# (rh) otherwise ld does not export any symbol
	QMAKE_LFLAGS_DEBUG += -Wl,--export-all-symbols
	QMAKE_LFLAGS_RELEASE += -Wl,--export-all-symbols
} else {
	LIBS += ws2_32.lib advapi32.lib shell32.lib
}
DEFINES += MAKE_KDE MAKE_KDEWIN32_LIB

SOURCES = \
bootstrap.cpp \
fcntl.c \
dummy.cpp \
fsync.c \
getenv.c \
inet.c \
grp.c \
kde_file_win.c \
mmap.c \
net.c \
pwd.c \
realpath.c \
readdir.c \
resource.c \
signal.c \
stdlib.c \
string.c \
syslog.c \
time.c \
uname.c \
unistd.c \
win32_utils.c \
win32_utils2.cpp
