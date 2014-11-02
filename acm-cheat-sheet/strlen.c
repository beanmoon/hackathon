#include <stdio.h>


size_t strlen2(char * str){
  const char * s;
  for(s=str; *s; s++){}
  return s - str;
}

int main(){
  printf("%s\n","hello");
  printf("%lu\n", strlen2("hello,world"));
}
