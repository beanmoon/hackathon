#include <stdio.h>

size_t strlen(const char *str){
  const char *s;
  for(s=str; *s; s++) {}
  return(s-str);
}

int main(){
  printf("%lu\n", strlen("hello"));
}
