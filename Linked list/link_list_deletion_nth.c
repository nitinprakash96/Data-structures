/*
* This program deletes a node at the nth position in a singly linked list.
*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* head;

void Insert(int data);
void Print();
void Delete(int n);

int main() {
	int i, n, x, y;

	head = NULL;
	
	printf("How many numbers> ");
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		printf("Enter a number: ");
		scanf("%d", &x);

		Insert(x);
		Print();
	}
	printf("Enter a position> \n");
	scanf("%d", &y);
	Delete(y);
	Print();
return 0;
}

void Delete(int n) {
	struct Node* temp1 = head;
	if(n == 1) {
		head = temp1 -> next;
		free(temp1);
		return;
	}

	int i;
	for(i = 0; i < n - 2; i++)
		temp1 = temp1 -> next; //temp1 points to (n-1)th node

	struct Node* temp2 = temp1 -> next;
	temp1 -> next = temp2 -> next; //(n + 1)th node
	free(temp2); //delete temp2
}

void Insert(int x) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp -> data = x;
	temp -> next = head;
	head = temp;
}

void Print() {
	struct Node* temp = head;
	printf("List is> ");
	while(temp != NULL) {
		printf("%d ", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}
