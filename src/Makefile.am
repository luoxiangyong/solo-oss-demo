AUTOMAKE_OPTIONS=foreign 
AM_CPPFLAGS = -I${top_srcdir}/include -I/opt/local/include
#AM_LDFLAGS  = -L/opt/local/lib -lintl

bin_PROGRAMS = solo-hello solo-navi-viewer

solo_hello_SOURCES = solo_hello.c
solo_hello_LDADD = libsolo-basic.la
solo_hello_LDFLAGS =  @INTL_EXTRA_LIBS@ 

solo_navi_viewer_SOURCES 	= \
			solo_navi_viewer.cpp \
			NavigationView.cpp \
			NavigationView.h \
			moc-NavigationView.cc\
			MainWindow.h\
			MainWindow.cpp\
			moc-MainWindow.cc
			
solo_navi_viewer_SOURCES 	+= \
			WebEngineView.h\
			WebEngineView.cpp\
			moc-WebEngineView.cc

clean-local:
	rm -rf moc-*.cc

solo_navi_viewer_CXXFLAGS 	= @MY_QT5_CPPFLAGS@ -fPIC -std=c++11
solo_navi_viewer_LDFLAGS 	= @QT5_LIBS@  @INTL_EXTRA_LIBS@  #solo-oss-demo.res

lib_LTLIBRARIES 			= libsolo-basic.la
libsolo_basic_la_SOURCES 	= solo_basic.c ../include/solo_basic.h
libsolo_basic_la_LDFLAGS 	=  -no-undefined -version-info 0:0:0
libsolo_basic_la_CFLAGS		= -DSOLO_BUILD_DLL 

# qt project stuff
moc-%.cc: %.h
	@MOC@ -o$@ $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS)\
			$(CPPFLAGS) $(MOC_CPPFLAGS) $<

ui-%.h: %.ui
	@UIC@ -o $@ $<

qrc-%.cc: %.qrc
	@RCC@ -o $@ $<
