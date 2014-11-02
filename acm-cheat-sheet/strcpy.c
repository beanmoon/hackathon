#include <stdio.h>

char* strcpy(char *to, const char *from){
  //  assert(to != NULL && from != NULL);
  if(to != NULL && from != NULL){
    char *p = to;
    while((*p++ = *from++) != '\0'){}
    return to;
  }else{
    printf("%s\n", "Null string not accepted");
  }
}


int main() {
  char to[] = "hello";
  char from[] = "hi";
  printf("%s\n", strcpy(to, from));
  return 2;
}
