#include <stdio.h>

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

int main() {
  char * pattern = "abbaabb";
  int i = 0, len=strlen(pattern);
  int next[len];
  for(; i<len; i++)
    next[i] = -2;
    compute_prefix(pattern, next);
  GetNextval(pattern, next);
  for(i=0; i<len; i++)
    printf("%d\n", next[i]);
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
void computeLPSArray(char *pat, int M, int *lps);
 
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    // create lps[] that will hold the longest prefix suffix values for pattern
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0;  // index for txt[]
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }
 
      if (j == M)
      {
        printf("Found pattern at index %d \n", i-j);
        j = lps[j-1];
      }
 
      // mismatch after j matches
      else if (i < N && pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); // to avoid memory leak
}
 
void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;  // lenght of the previous longest prefix suffix
    int i;
 
    lps[0] = 0; // lps[0] is always 0
    i = 1;
 
    // the loop calculates lps[i] for i = 1 to M-1
    while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (len != 0)
         {
           // This is tricky. Consider the example AAACAAAA and i = 7.
           len = lps[len-1];
 
           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}
 
// Driver program to test above function
int main()
{
   char *txt = "ABABDABACDABABCABAB";
   char *pat = "ABABCABAB";
   KMPSearch(pat, txt);
   return 0;
}
