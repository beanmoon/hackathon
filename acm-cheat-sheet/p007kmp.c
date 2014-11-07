#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeLPSArray(char *pat, int *lps){
  int plen = strlen(pat);
  int i=1, j, len=0;
  lps[0] = 0;

  while(i < plen){
    if(pat[i] == pat[len]){
      len++;
      pat[i] = len;
    }
  }

}

int main() {
  char * pattern = "aaacaaaa";
  int i = 0, len=strlen(pattern);
  int next[len];
  for(; i<len; i++)
    next[i] = -2;
  compute_prefix(pattern, next);
  //GetNextval(pattern, next);
  for(i=0; i<len; i++)
    printf("%d\n", next[i]);
}


/*
void compute_prefix(const char *pattern, int next[]) {
  int i;
  int j = -1;
  const int m = strlen(pattern);
  next[0] = j;
  for (i = 1; i < m; i++) {
    while (j > -1 && pattern[j + 1] != pattern[i]) j = next[j];
    if (pattern[i] == pattern[j + 1]) j++;
    next[i] = j; }
}


void GetNextval(char* p, int next[])  
{  
  int pLen = strlen(p);  
  next[0] = -1;  
  int k = -1;  
  int j = 0;  
  while (j < pLen - 1)  
    {  
      //p[k]表示前缀，p[j]表示后缀    
      if (k == -1 || p[j] == p[k])  
        {  
	  ++j;  
	  ++k;  
	  //较之前next数组求法，改动在下面4行  
	  if (p[j] != p[k])  
	    next[j] = k;   //之前只有这一行  
	  else  
	    //因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]  
	    next[j] = next[k];  
        }  
      else  
        {  
	  k = next[k];  
        }  
    }  
}  
*/
