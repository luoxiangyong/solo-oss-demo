#include "solo_basic.h"
#include <stdio.h>
#include <locale.h>
#include <libintl.h>

int main(int argn, char** argv)
{
  char* old = NULL;

  printf("solo-oss-demo: console based app\n");
  
  setlocale(LC_ALL,"");
  old = bindtextdomain(NULL,NULL);
  printf("OLD:%s\n", old);
  bindtextdomain("solo-oss-demo", "/usr/share/locale");
  textdomain("solo-oss-demo");
  
  printf("%s", solo_get_hello());
  printf(_("hello from  Xiangyong Luo :)\n"));
  
  printf("test_fun = %d\n", solo_test_fun());

  return 0;
}
