AUTOMAKE_OPTIONS=foreign 
AM_CPPFLAGS = -I../include

bin_PROGRAMS = so_hello so_hello_gui

so_hello_SOURCES = main.c
so_hello_LDADD = libsohello.la


so_hello_gui_SOURCES = so_gui.cpp
#so_hello_gui_LDADD = libQtCore.so libQtWidgets
so_hello_gui_CPPFLAGS = -I/usr/include/qt5 -fPIC
so_hello_gui_LDFLAGS = -lQt5Core -lQt5Widgets
#sohello_basiclibdir=$(libdir)
#sohello_basiclib_PROGRAMS = sohello_basic.so
#sohello_basic_so_SOURCES = hello.c

lib_LTLIBRARIES = libsohello.la
libsohello_la_SOURCES = hello.c ../include/so_hello.h
libsohello_la_LDFLAGS=-shared -fPIC
