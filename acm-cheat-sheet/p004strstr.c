#include <stdio.h>

char * strstr2(const char *str, const char *s){
  if(!*s) return str;
  char *p1;
  char *p2;
  char *p_advance = str;
  while(*p1=&s[1]; *p1; p1++){
    p_advance++;
  }
  
  for(p1=str; *p_advance; p_advance++){
    char *p_old = p1;
    p2 = s;
    while(*p1 && *p2 && *p1 == *p2){
      p1++; 
      p2++;
    }

    if(!*p2) return p1;
    p1++;
  }

}


int main() {
  const char* str1 = "hello,world";
  const char* str2 = "wo";
  print("%s\n", strstr2(str1,str2));
}
