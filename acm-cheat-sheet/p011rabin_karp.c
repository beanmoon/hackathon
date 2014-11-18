#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define R 256
#define Q 0xfff1

long hash(const char *str, int len){
  long result = 0;
  for(int i=0; i<len; i++){
    /* a stupid mistake */
    /* result = (result + str[i]*R) % Q; */ 
    result = (result*R + str[i]) % Q;
  }
  return result;
}

long rehash(long value, char first, char next, long RM){
  long nhash = (value + Q - first * RM % Q) % Q;
  nhash = (nhash * R + next) % Q;
  return nhash;
}

int check(const char *pattern,const char *substring){
  return 1;
}

int rabin_karp(const char *text, const char *pattern){
  int n = strlen(text);
  int m = strlen(pattern);
  long RM = 1;
  int i = 0;
  for(i = 0; i<m-1; i++)  RM = (RM*R) % Q;

  long pattern_hash = hash(pattern, m);
  long text_hash = hash(text, m);
  printf("pattern_hash = %ld\n", pattern_hash);

  for(i=0; i<=n-m; i++){
    printf("text = %s, text_hash = %ld\n", &text[i], text_hash);
    
    if(text_hash == pattern_hash){
      if(check(pattern, &text[i])){
	  return i;
      }
    }
    text_hash = rehash(text_hash, text[i], text[i+m], RM);
  }
   
  return -1;
}


int main(){
  char *text = "this is a simple example";
  /* char *text = "baaaaaaaaaaaaaaaaaaa"; */
  char *pattern = "example";
  
  int index = rabin_karp(text, pattern);
  printf("%d\n", index);
}
