/*
* Testing the implementations of the functions created for
* operating Circular Linked List.
*/

#include <stdio.h>
#include "CLinkedList.h"

int main(int argc, const char * argv[]) {
	struct CLLNode * head = NULL;

	insertInBeginning(&head, 10);
	insertInBeginning(&head, 0);
	insertInBeginning(&head, -10);
	insertAtEnd(&head, 20);

	deleteInBeginning(&head);
	printList(head);

return 0;
}
