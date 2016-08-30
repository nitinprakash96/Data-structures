#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

Queue *getNewQueue(int capacity) {
	Queue *newQueue = malloc(sizeof(Queue));

	if (!newQueue) {
		printf("ERROR: Allocating memory");
		return NULL;
	}

	newQueue->capacity = capacity;
	newQueue->front = -1;
	newQueue->rear = -1;

	newQueue->array = malloc(newQueue->capacity * sizeof(int));

	return newQueue;
}

int isEmpty(Queue *queue) {
	return (queue->front == -1 && queue->rear == -1);
}

int isFull(Queue *queue) {
	return (queue->rear + 1) % queue->capacity == queue->front;
}

int getQueueSize(Queue *queue) {
	return (queue->capacity - queue->front + queue->rear + 1) % queue->capacity;
}

void enqueue(Queue *queue, int data) {
	// Check for queue overflow condition
	if (isFull(queue)) {
		printf("\nQueue overflow\n");
	} else {
		queue->rear = (queue->rear+1) % queue->capacity;
		queue->array[queue->rear] = data;
        
		if (queue->front == -1) {
			queue->front = queue->rear;
		}
    	}
}

int dequeue(Queue *queue)  {
	if (isEmpty(queue)) {
		printf("\nThe queue is empty\n");
		return -1;
	} else {
        	int data = queue->array[queue->front];
        	// Check for the bounds of the front and rear pointers
        	if (queue->front == queue->rear)  {
        		queue->front = queue->rear = -1;
		} else {
        		queue->front = (queue->front + 1) % queue->capacity;
        	}
	return data;
    }
}

