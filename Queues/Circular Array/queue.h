#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
// Structure representing a single entry in the queue
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

void Print(Queue *queue);
