#include<stdio.h>
#include<stdlib.h>

long long int myHeap[1000005]={0};
long long int count=0;

//Latest Simple Heap!

void swapheap(long long int a, long long int b)
{
	long long int temp=myHeap[a];
	myHeap[a]=myHeap[b];
	myHeap[b]=temp;
}

void upshift(long long int a)
{
	while(a>1)
	{
		if(myHeap[a/2]>myHeap[a])
		{
			swapheap(a,a/2);
			a=a/2;
		}
		else
			return;
	}
}

void downshift(int i) //Shifts down the tree swapping with the children whenever required.
{
	while(i<=count)
	{
		if(i*2<=count)
		{
			if((i*2+1<=count && myHeap[i*2]<myHeap[i] && myHeap[i*2]<myHeap[i*2+1]) || (myHeap[i*2]<myHeap[i] && i*2+1>count))
			{
				swapheap(i,i*2);
				i=i*2;
			}
			else if(i*2+1<=count && myHeap[i*2+1]<myHeap[i] && myHeap[i*2+1]<=myHeap[i*2])
			{
				swapheap(i,i*2+1);
				i=i*2+1;
			}
			else
				break;
		}
		else
			break;
	}
}

void insert(long long int a)
{
	count++;
	myHeap[count]=a;
	upshift(count);
}

void deletetop()
{
	if(count>0)
	{
		myHeap[1]=myHeap[count];
		count--;
		downshift(1);
	}
}

int main()
{
	long long int n,m,a,b,c,i,j,k;
	scanf("%lld", &n);
	for(i=0;i<n;i++)
	{
		scanf("%lld", &a);
		insert(a);
	}
	for(i=0;i<n;i++)
	{
		printf("%lld\n", myHeap[1]);
		deletetop();
	}
	return 0;
}
