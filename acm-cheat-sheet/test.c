#include <stdio.h>

int main(){
  int i;
  for(i = 1; i<10; i++){
    printf("%d\n", i);
  }
  char const * str = "hello,world";
  //  const char * str = "hello,world";
  const char *s = "wo";
  printf("%s\n", strstr(str,s));
}
