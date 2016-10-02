#include<stdio.h>
#include<stdlib.h>
#include"program.h"

void push(stack* st, int n)
{
        if(isFull(st))
        {
                printf("Stack is filled\n");
                return ;
        }
        st->last = st->last + 1;
        st->a[st->last] = n;
}
int pop(stack* st)
{
        if(isEmpty(st))
        {
                printf("Stack is empty\n");
                return -1;
        }
        int temp = st->a[st->last];
        st->a[st->last] = -1;
        st->last -=1;
return temp;
}

int peek(stack* st)
{
        if(isEmpty(st))
        {
                printf("stack is empty\n");
                return -1;
        }
        int temp = st->a[st->last];
        return temp;
}
int isEmpty(stack* st)
{
 	if(st->last == 0) return 1;
	else return 0;
}
int isFull(stack* st)
{
	if(st->last == 199) return 1;
	else return 0;
}

