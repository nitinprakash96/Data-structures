#include<stdio.h>
#include<stdlib.h>
#include "stacks.h"

void push(stack *s,int x) {
	if(s->top == -1)
		printf("stack full \n");
	else
		s->a[++s->top] = x;
}

int pop(stack *s) {
	int x;
	if(s->top < 0)
		printf("Stack Empty \n");
	else {
		x = s->a[s->top--];
	return x;
	}
}

void display(stack s) {
	int i;
	for(i = s.top; i >= 0; i--) 
		printf("%d\n", s.a[i]);
	}
