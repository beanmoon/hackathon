#include <stdio.h>

#define INT_MAX  10000
#define INT_MIN  -10000

int myatoi(const char * str){
  int num = 0;
  int sign = 1;
  const int length = strlen(str);
  int i = 0;

  while(str[i] == ' ' && i < length) i++;
  if(str[i] == '+') i++;
  if(str[i] == '-'){
    sign = -1;
    i++;
  }

  for(; i<length; i++){
    if(str[i] < '0' || str[i] > '9')
      break;
    if(num > INT_MAX/10 || (num == INT_MAX/10 && str[i] - '0' > INT_MAX % 10))
      return sign == -1 ? INT_MIN : INT_MAX;
    num = num * 10 + str[i] - '0';
  }
		      
  return num * sign;
}

int main() {
  printf("%d\n", myatoi("   2232"));
}
