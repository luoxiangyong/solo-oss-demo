#ifndef SOLO_BASIC_H
#define SOLO_BASIC_H

#ifdef WIN32
#ifdef SOLO_BUILD_DLL
#define SOLO_API __declspec(dllexport)
#else
#define SOLO_API __declspec(dllimport)
#endif
#else
#define SOLO_API
#endif

#define _(String) gettext(String)
#define gettext_noop(String) String
#define N_(String) gettext_noop(String)


SOLO_API const char* solo_get_hello();
SOLO_API int solo_test_fun();

#endif // SOLO_BASIC_H
