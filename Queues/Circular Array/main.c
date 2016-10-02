/*
* Queues Implementation using circular arrays
* References: DSA Made Easy.
*/
#include <stdio.h>
#include "queue.h"

int main(int argc, const char *argv[]) {
	Queue *intQueue = getNewQueue(5);
	
	int i;

	enqueue(intQueue, 24);

	enqueue(intQueue, 25);

	enqueue(intQueue, 26);

	enqueue(intQueue, 27);

	int testData = dequeue(intQueue);
	int size = getQueueSize(intQueue);

	printf("Size: %d\n", size);

	testData = dequeue(intQueue);
//	testData = dequeue(intQueue);

	printf("\nThe data just taken out is %d\n", testData);


	return 0;
}
