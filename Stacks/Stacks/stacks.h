#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int a[100];
	int top;
} stack;

void push(stack *s, int x);

int pop(stack *s);

void display(stack s);
