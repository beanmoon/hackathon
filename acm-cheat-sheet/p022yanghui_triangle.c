#include <stdio.h>
#include "p020queue.c"

void yanghui_triangle(const int n) {
  int i = 1;
  queue_t *q = queue_create(100);
  /* 预先放入第一行的 1 */ 
  queue_push(q, i);

  for(i=0;i<=n;i++){ /* 逐行处理 */ 
    int j;
    int pre = 0;
    int cur;
    int tmp;

    queue_push(q, pre); /* 在各行间插入一个 0*/

    /* 处理第 i 行的 i+2 个系数(包括一个 0)*/ 
    for(j = 0; j < i+2; j++) {
      cur = queue_pop(q); /* 读取一个系数,放入 t*/ 
      tmp = pre + cur; /* 计算下一行系数,并进队列 */ 
      queue_push(q, tmp);

      /* if(j != i+1) { */ // equals to code below
      if(cur != 0) { 
	printf("%d ",cur);
      }
      pre = cur; /* 打印一个系数,第 i+2 个是 0*/ 
    }
    printf("\n");
  }
}

int main() {
  yanghui_triangle(30);
}
