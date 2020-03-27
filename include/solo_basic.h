#ifndef SOLO_BASIC_H
#define SOLO_BASIC_H

#include <libintl.h>

#define _(String) gettext(String)
#define gettext_noop(String) String
#define N_(String) gettext_noop(String)

void solo_say_hello();

#endif // SOLO_BASIC_H
