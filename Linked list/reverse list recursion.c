#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* head;

void Reverse(struct Node* p) {
	if (p -> next = NULL) {
		head = p;
		return;
	}
	Reverse(p -> next);
	struct Node* q = p -> next;
	q -> next = p;
	p -> next = NULL;
}

int main() {
	int n, i, x;

	printf("Enter the number of elements in the list> ");
	scanf("%d", &n);

	for(i = 0; i < n; i++) {
		printf("\nEnter element %d> ", i + 1);
		scanf("%d", &x);
		Reverse(x);

	}
return 0;
}
