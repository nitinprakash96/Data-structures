#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"program.h"

int main() {
	stack* st;
	st = (stack*)malloc(sizeof(stack));
	int i= 0;
	for(i=0;i<99;i++) st->a[i] = -1;
	char p[200];
	printf("ENTER STRING VALUES\n");
	scanf("%s",p);
	int a,b,c,d;
	printf("Enter the values \n");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int n = strlen(p);
	int temp1,temp2;
	for(i=0;i<n;i++)
	{
		if(p[i] == '+')
		{
			temp1= pop(st);
			temp2= pop(st);
			temp1+=temp2;
			push(st,temp1);
		} else if(p[i] == '-'){
			temp1= pop(st);
			temp2= pop(st);
			temp2-=temp1;
			push(st,temp2);
		} else if(p[i] == '/'){
			temp1= pop(st);
			temp2= pop(st);
			temp2/=temp1;
			push(st,temp2);
		} else if(p[i] == '*'){
			temp1= pop(st);
			temp2= pop(st);
			temp2*=temp1;
			push(st,temp2);
		} else if(p[i] >='a' && p[i] <= 'd'){
			if(p[i] == 'a') push(st,a);
			else if(p[i] == 'b') push(st,b);
			else if(p[i] == 'c') push(st,c);
			else if(p[i] == 'd') push(st,d);
		} else{
			printf("input invalid");
		}
	}
			printf("Answer is %d\n",pop(st));
return 0;
}
