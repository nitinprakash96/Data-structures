/*
* This iterative program inserts a node at any random position inside a linked list
*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* head;
void Insert(int data, int n);
void Print();

int main() {
	int n, i, x, y;

	head = NULL;

	printf("How many numbers> ");
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		printf("Enter the number: \n");
		scanf("%d", &x);

		printf("Enter the position: \n");
		scanf("%d", &y);
		Insert(x, y);
		Print();
	}

}

void Insert(int data, int n) {
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));
	temp1 -> data = data;
	temp1 -> next = NULL;
	if(n == 1) {
		temp1 -> next = head;
		head = temp1;
		return;
	}
	int i;

	struct Node* temp2 = head;
	for(i = 0; i < n - 2; i++) {
		temp2 = temp2 -> next;
	}
	temp1 -> next = temp2 -> next;
	temp2 -> next = temp1;
}

void Print() {
	struct Node* temp = head;
	while(temp != NULL) {
		printf("%d ", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}
