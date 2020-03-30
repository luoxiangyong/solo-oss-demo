#include "config.h"
#include <stdio.h>
#include "solo_basic.h"

const char* solo_get_hello()
{
  static const char* hello = "Hello From:solo-basic library!\n";
  printf("solo_get_hello() -> \n");
  return hello;
}

int solo_test_fun()
{
  /* 
  long pos = ftell(stdin);
  FILE* f = fopen("test.txt", "w+");
  if(f != NULL) {
    fwrite("test\n",10,1, f);
    fclose(f);
    fprintf(stdout,"writing to test.txt\n");
  }
  */
  return 99999;
}
