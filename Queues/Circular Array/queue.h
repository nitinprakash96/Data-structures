#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayQueue {
	int front, rear;
	int capacity;
	int *array;
}Queue;

Queue *getNewQueue(int capacity);

int isEmpty(Queue *queue);

int isFull(Queue *queue);

int getQueueSize(Queue *queue);

void enqueue(Queue *queue, int data);

int dequeue(Queue *queue);
