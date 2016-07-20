/*
* CLinkedList.h
* Circular Linked List
*/

#ifndef __Circular_Linked_List__CLinkedList__
#define __Circular_Linked_List__CLinkedList__

#include <stdio.h>

// Structure that defines a single node in the circular linked list
struct CLLNode{
	int data;
	struct CLLNode *next;
};

/*
* Prints all data inside unique nodes in the circular linked list.
*/
void printList(struct CLLNode * head);


/*
* Calculates and returns the number of unique nodes present in the linked list.
*/
int listLength(struct CLLNode * head);


/*
* Returns a new circular node with the data associated with it
* equal to the one that is passed as the argument.
* A circular node is a node that has the next pointer pointing to itself.
*/
struct CLLNode *getNewCircularNode(int data);


/*
* A function to insert a node at the beginning of the circular linked list.
*/
void insertInBeginning(struct CLLNode **head, int data);


/*
* A function to insert a node at the end of the circular linked list.
*/
void insertAtEnd(struct CLLNode ** head, int data);


/*
* A function to delete the node at the beginning.
*/
void deleteInBeginning(struct CLLNode ** head);


/*
* A function to delete the node at the end.
*/
void deleteAtEnd(struct CLLNode ** head);


#endif /* defined(__Circular_Linked_List__CLinkedList__) */
