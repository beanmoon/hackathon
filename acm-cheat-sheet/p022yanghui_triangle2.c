#include <stdio.h>
#include "p020queue.c"

/**
 * 如下杨辉三角的实现代码相当于在原有的每一行两端都加上一个辅助0，以方便做加法运算
 *             0 1 0
 *            0 1 1 0
 *           0 1 2 1 0
 *          0 1 3 3 1 0
 *  ............................
 * @author beanmoon
 */
void yanghui_triangle(int n){
  // 打印杨辉三角时，对对列的容量也是有要求的，队列的容量至少需要是n+3
  queue_t *q = queue_create(10);
  int cur = 1;
  queue_push(q, cur);

  for(int i = 0; i <= n; i++){
    int tmp = 0, pre = 0;
    queue_push(q,pre);
    /* 对于第i行需要遍历i+1次，因为在此循环体中我们需要向队列中插入下一行的i+1个数，
       同时也需要从现有的队列中弹出i+1个数（包括外层循环开始时加进去的那个0） */
    for(int j = 0; j < i+2; j++){
      cur = queue_pop(q);
      // 将现在从队列中弹出的数与上一个从队列中弹出的数相加，得出的就是下一行的第j个数
      tmp = cur + pre;
      queue_push(q, tmp);
      /* 如果cur=0，说明是内层循环的第j+1，即最后一次循环
	 因为cur是我们在外层循环开始的时候人为加入队列中的那个0，故此时不需要打印输出 */
      if(cur != 0)
	printf("%d ", cur);
      // 记录上一次从队列中弹出的值
      pre = cur;
    }
    printf("\n");
  }
}

int main() {
  yanghui_triangle(7);
}
