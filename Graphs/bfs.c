#include<stdio.h>
#include<stdlib.h>

struct Queue{
	int val;
	struct Queue* next;
};

int a,b;

struct Queue* head=NULL;
truct Queue* tail=NULL;

struct List{
	int val;
	struct List* next;
};

struct List* mylist[100000]={NULL};
int marked[100000]={0};
int counter[100000]={0};

void enqueue(int x)
{
	struct Queue* temp=malloc(sizeof(struct Queue));
	temp->val=x;
	temp->next=NULL;
	if(head==tail && head==NULL)
	{
		head=temp;
		tail=head;
	}
	else
	{
		head->next=temp;
		head=head->next;
	}
}

void dequeue()
{
	if(head==tail && head!=NULL)
	{
		tail=NULL;
		head=NULL;
	}
	else if(head!=NULL)
		tail=tail->next;
}

int front()
{
	if(tail!=NULL)
		return tail->val;
}

void bfs()
{
	int val;
	marked[front()]=1;
	while(tail!=NULL)
	{
		val=front();
		dequeue();
		struct List* temp=mylist[val];
		while(temp!=NULL)
		{
			if(marked[temp->val]==0)
			{
				marked[temp->val]=1;
				enqueue(temp->val);
				counter[temp->val]+=counter[val]+1;
			}
			temp=temp->next;
		}
	}
	printf("%d\n", counter[b]);
}

int main()
{
	int n,m,i,j,k,c;
	scanf("%d%d", &n, &m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d", &a, &b);
		//We insert at the head so insertion in in O(1)
		struct List* temp=malloc(sizeof(struct List));
		temp->val=b;
		temp->next=mylist[a];
		mylist[a]=temp;
		struct List* temp2=malloc(sizeof(struct List));
		temp2->val=a;
		temp2->next=mylist[b];
		mylist[b]=temp2;
	}
	//Printing the Adjacency List
	/*for(i=1;i<=n;i++)
	{
		struct List* temp=mylist[i];
		while(temp!=NULL)
		{
			printf("%d ", temp->val);
			temp=temp->next;
		}
		printf("\n");
	}*/
	scanf("%d%d", &a, &b);
	enqueue(a);
	bfs();// To get the shortest distance b/w a and b
	return 0;
}
