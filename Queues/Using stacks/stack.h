/* Program to implement a queue using two stacks */
#include<stdio.h>
#include<stdlib.h>
 
void push(struct sNode** top_ref, int new_data);
  
/* Function to pop an item from stack*/
int pop(struct sNode** top_ref);
  
/* Function to enqueue an item to queue */
void enQueue(struct queue *q, int x)
  
/* Function to dequeue an item from queue */
int deQueue(struct queue *q)
  
/* Function to push an item to stack*/
void push(struct sNode** top_ref, int new_data)
  
/* Function to pop an item from stack*/
int pop(struct sNode** top_ref)
