/*
* Reversing a linked list iteratively.
*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* Reverse(struct Node* head) {
	struct Node *next, *prev, *current;
	current = head;
	prev = NULL;
	while (current != NULL) {
		next = current -> next;
		current -> next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}

void Print(struct Node* head);
struct Node* Insert(struct Node* head, int data);

int main() {
	struct Node* head; // local variable
	int n, i, x;

	printf("Enter the number of elements in the list> ");
	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		printf("\nEnter element %d> ", i + 1);
		scanf("%d", &x);
		head = Insert(head, x);
	}
	Print(head);
	head = Reverse(head);
	Print(head);
return 0;
}

struct Node* Insert(struct Node* head, int data) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp -> data = data;
	temp -> next = NULL;
	if(head == NULL) head = temp;
	else {
		struct Node* temp1 = head;
		while(temp1 -> next != NULL) temp1 = temp1 -> next;
		temp1 -> next = temp;
	}
	return head;
}

void Print(struct Node* head) {
	while(head != NULL) {
		printf("%d\t", head -> data);
		head = head -> next;
	}
	printf("\n");
}
