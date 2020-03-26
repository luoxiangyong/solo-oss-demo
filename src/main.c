#include "so_hello.h"
#include <stdio.h>
#include <locale.h>
#include <libintl.h>

#define _(String) gettext(String)
#define gettext_noop(String) String
#define N_(String) gettext_noop(String)

int main(int argn, char** argv)
{
  char* old = NULL;
  setlocale(LC_ALL,"");
  old = bindtextdomain(NULL,NULL);
  printf("OLD:%s\n", old);
  bindtextdomain("so_hello", "/usr/share/locale");
  textdomain("so_hello");
  
  so_say_hello();
  printf(_("hello from  Xiangyong Luo :)\n"));
  
  return 0;
}
