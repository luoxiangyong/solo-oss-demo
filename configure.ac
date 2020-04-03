AC_INIT([solo-oss-demo], [1.0], [solo_lxy@126.com])
AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE([1.6 -Wall -Werror foreign])

LT_PREREQ([2.4.6])


AM_PROG_AR
AC_PROG_CC
#AC_PROG_RANLIB
AC_LIBTOOL_WIN32_DLL
LT_INIT
AC_PROG_LIBTOOL
AC_PROG_CXX

case "$host" in 
	*-mingw32*)
	INTL_EXTRA_LIBS=-lintl
	;;
	*-darwin*)
	INTL_EXTRA_LIBS="-lintl -L/opt/local/lib/"
	;;
	*-linux*)
	#INTL_EXTRA_LIBS="-lintl -L/opt/local/lib/"
	echo -e "==>> No need link libintl on linux platform"
	;;
	*)
	INTL_EXTRA_LIBS=
	;;
esac
AC_SUBST(INTL_EXTRA_LIBS,[$INTL_EXTRA_LIBS])

AC_DEFINE_UNQUOTED([THE_BUILD_HOST],["$host"],[构建用的平台])

PKG_CHECK_MODULES(QT5, [Qt5Core Qt5Gui,Qt5Widgets,Qt5WebKitWidgets,Qt5WebChannel], [
	AC_PATH_PROGS(MOC, [moc-qt5 moc], moc,`eval $PKG_CONFIG --variable=exec_prefix Qt5Core`/bin)
	AC_PATH_PROG(RCC, [rcc-qt5 rcc], rcc,`eval $PKG_CONFIG --variable=exec_prefix Qt5Core`/bin)
	AC_PATH_PROGS(UIC, [uic-qt5 uic], uic,`eval $PKG_CONFIG --variable=exec_prefix Qt5Core`/bin)
	], [
  	AC_MSG_ERROR([Qt 5 library not found])
])

# Retrieve Qt compilation and linker flags
MY_QT5_CPPFLAGS="`$PKG_CONFIG --cflags-only-I Qt5Core Qt5Gui Qt5Widgets` $CPPFLAGS"
MY_QT5_LDFLAGS="`$PKG_CONFIG --libs-only-L Qt5Core Qt5Gui Qt5Widgets` $LDFLAGS"
MY_QT5_LIBS="`$PKG_CONFIG --libs Qt5Core Qt5Gui Qt5Widgets` $LIBS"

AC_SUBST(MY_QT5_CPPFLAGS, [$MY_QT5_CPPFLAGS])
AC_SUBST(MY_QT5_LDFLAGS, [$MY_QT5_LDFLAGS])
AC_SUBST(MY_QT5_LIBS, [$MY_QT5_LIBS])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
	Makefile
	src/Makefile
])

AC_OUTPUT

AC_MSG_RESULT([])
AC_MSG_RESULT([========================================================================])
AC_MSG_RESULT([PKG_CONFIG: $PKG_CONFIG])
AC_MSG_RESULT([MY_QT5_CPPFLAGS: $MY_QT5_CPPFLAGS])
AC_MSG_RESULT([MY_QT5_LDFLAGS: $MY_QT5_LDFLAGS])
AC_MSG_RESULT([MY_QT5_LIBS: $MY_QT5_LIBS])
AC_MSG_RESULT([QT5_CFLAGS: $QT5_CFLAGS])
AC_MSG_RESULT([QT5_LIBS: $QT5_LIBS])
AC_MSG_RESULT([MOC: $MOC])
AC_MSG_RESULT([RCC: $RCC])
AC_MSG_RESULT([UIC: $UIC])
AC_MSG_RESULT([host: $host])
AC_MSG_RESULT([INTL_EXTRA_LIBS: $INTL_EXTRA_LIBS])

AC_MSG_RESULT([========================================================================])


