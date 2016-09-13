#include<stdio.h>
#include<stdlib.h>
#include "stacks.h"

int main(int argc, char *argv[]) {
	stack s1;
	int m,n;

	s1.top = -1;
	push(&s1, 10);
	display(s1);
	m = pop(&s1);
	pop(&s1);
	display(s1);
return 0;
}
