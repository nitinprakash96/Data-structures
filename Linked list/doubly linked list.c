/*
 Doubly linked list implementation
*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head; //pointer to head node

struct Node* GetNewNode(int x) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = x;
	newNode -> prev = NULL;
	newNode -> next = NULL;
	return newNode;
}

void InsertAtHead(int x) {
	struct Node* newNode = GetNewNode(x);
	if(head == NULL) {
		head = newNode;
		return;
	}
	head -> prev = newNode;
	newNode -> next = head;
	head = newNode;
}

void InsertAtTail(int x) {
	struct Node* temp = head;
        struct Node* newNode = GetNewNode(x);
        if(head == NULL) {
                head = newNode;
                return;
        }
	while(temp -> next != NULL) {
		temp = temp -> next; //go to last node
		temp -> next;
		newNode -> prev = temp;
	}
}

void Print() {
	struct Node* temp = head;
	printf("Forward> ");
	while(temp != NULL) {
		printf("%d ", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}

void ReversePrint() {
	struct Node* temp = head;
	if(temp == NULL) return; //empty linked list => exit
	
	//going to last node
	while(temp -> next != NULL) {
		temp = temp -> next;
	}
	//traversing backwards using prev pointer
	printf("Backwrds> ");
	while(temp != NULL) {
		printf("%d ", temp -> data);
		temp = temp -> prev;
	}
	printf("\n");
}

int main() {
	int n, i, x, y;

	head = NULL; //empty list

	printf("Enter how many numbers in the list> ");
	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		printf("Enter the number to insert at head> ");
		scanf("%d", &x);
		InsertAtHead(x); Print(); ReversePrint();	//To insert at tail, use InsertAtTail function
	}

return 0;
}
