typedef struct stack{
	int a[200];
	int last;
}stack;

void push(stack* st, int n);	
int pop(stack* st);
int peek(stack* st);
int isEmpty(stack* st);
int isFull(stack* st);

