#include <stdio.h>

int main(){
  char const * str = "hello,world";
  //  const char * str = "hello,world";
  *str = "hi";
  printf("%s\n",str);
}
