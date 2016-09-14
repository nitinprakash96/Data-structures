#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

int main() {
   	/* Create a queue with items 1 2 3*/
   	struct queue *q = (struct queue*)malloc(sizeof(struct queue));
   	q->stack1 = NULL;
   	q->stack2 = NULL;
   	enQueue(q, 1);
   	enQueue(q, 2);
   	enQueue(q, 3);    
  
   	/* Dequeue items */
   	printf("%d  ", deQueue(q));
   	printf("%d  ", deQueue(q));
   	printf("%d  ", deQueue(q));  
  
   	getchar();
return 0;
}
