#include "solo_basic.h"
#include <stdio.h>
#include <locale.h>


int main(int argn, char** argv)
{
  char* old = NULL;

  printf("solo-oss-demo: console based app\n");
  
  setlocale(LC_ALL,"");
  old = bindtextdomain(NULL,NULL);
  printf("OLD:%s\n", old);
  bindtextdomain("solo-oss-demo", "/usr/share/locale");
  textdomain("solo-oss-demo");
  
  solo_say_hello();
  printf(_("hello from  Xiangyong Luo :)\n"));
  
  return 0;
}
