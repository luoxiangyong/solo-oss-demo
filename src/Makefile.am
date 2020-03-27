AUTOMAKE_OPTIONS=foreign 
AM_CPPFLAGS = -I../include

bin_PROGRAMS = solo-hello solo-navi-viewer

solo_hello_SOURCES = solo_hello.c
solo_hello_LDADD = libsolo-basic.la


solo_navi_viewer_SOURCES 	= solo_navi_viewer.cpp NavigationView.cpp NavigationView.h moc-NavigationView.cc
solo_navi_viewer_CXXFLAGS 	= @MY_QT5_CPPFLAGS@ -fPIC
solo_navi_viewer_LDFLAGS 	= @MY_QT5_LIBS@


lib_LTLIBRARIES 			= libsolo-basic.la
libsolo_basic_la_SOURCES 	= solo_basic.c ../include/solo_basic.h
libsolo_basic_la_LDFLAGS 	= -shared -fPIC


# qt project stuff
moc-%.cc: %.h
	@MOC@ -o$@ $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(MOC_CPPFLAGS) $<

ui-%.h: %.ui
	@UIC@ -o $@ $<

qrc-%.cc: %.qrc
	@RCC@ -o $@ $<