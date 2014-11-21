#include <stdio.h>
#include <math.h>
#include "p014stack.c"

/* implemention with stack
 */
void convert_base(int n, const int d){
  stack_type *s = stack_create(10);
  
  int e;
  while(n != 0){
    e = n % d;
    stack_push(s, e);
    n /= d;
  }
  while(!stack_empty(s)){
    e = stack_pop(s);
    printf("%d ", e);
  }
  printf("\n");
}



/*
 * implemention with array
 */
int MAX = 64;
void convert_base2(int n, const int d){
  int stack[MAX];
  int e, top = -1;
  while(n != 0){
    e = n % d;
    stack[++top] = e;
    n /= d;
  }

  while(top >= 0){
    e = stack[top--];
    printf("%d ", e);
  }
  printf("\n");
  
}


int restore(char *s, int d){
  int len = strlen(s);
  int num = 0, result = 0;
  for(int i=0; i<len; i++){
    if(s[i] >= '0' && s[i] <='9'){
      num = s[i] - '0';
    }else if(s[i] >= 'A' && s[i] <= 'F'){
      num = s[i] - 'A' + 10;
    }else{
      num = s[i] - 'a' + 10;
    }
    /* result += num * pow(d, len-1-i); */
    result = result*d + num;
  }
  return result;
}


int main() {
  convert_base2(79,8);
  printf("0x55f = %d in denary\n", restore("55f", 16));
}
