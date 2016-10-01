#include<stdio.h>
#include<stdlib.h>

//For storing numbers with upto 10^5 digits

char stack[10000];
int start=-1;
int state;

struct Trie{
	char val;
	int count;
	struct Trie* children[11];
};

struct Trie* mytrie=NULL;

void delete(char A[11])
{
	if(search(A)!=0)
	{
		int i=0;
		struct Trie* temp=mytrie;
		while(i<11 && A[i]!='\0')
		{
			temp=temp->children[A[i]-'0'];
			i++;
		}
		(temp->count)--;
	}
}

void frees(struct Trie* temp)
{
	int i;
	if(temp==NULL)
		return;
	for(i=0;i<11;i++)
	{
		frees(temp->children[i]);
	}
	temp=NULL;
	free(temp);
	return;
}

void insert(char A[11])
{
	int i,j,k;
	i=0;
	struct Trie* temp=mytrie;
	while(i<11 && A[i]!='\0')
	{
		if(temp->children[A[i]-'0']==NULL)
		{
			temp->children[A[i]-'0']=malloc(sizeof(struct Trie));
			for(k=0;k<10;k++)
				temp->children[A[i]-'0']->children[k]=NULL;
		}
		temp=temp->children[A[i]-'0'];
		temp->val=A[i];
		if(temp->count>0)
			state=1;
		i++;
	}
	temp->count++;
	for(k=0;k<10;k++)
		if(temp->children[k]!=NULL)
			state=1;
}

int search(char A[11])
{
	struct Trie* temp=mytrie;
	int i=0;
	while(i<11 && A[i]!='\0')
	{
		temp=temp->children[A[i]-'0'];
		if(temp==NULL)
			return 0;
		i++;
	}
	return temp->count;
}

void printstack()
{
	int i;
	for(i=1;i<=start;i++) //We print from the 2nd element in stack as the first element just has the start "#" value which we dont need to print
		printf("%c",stack[i]);
	printf("\n");
}

void dfs(struct Trie* temp)
{
	int i;
	if(temp!=NULL)
	{
		start++;
		stack[start]=temp->val;
		int k=temp->count;
		while(k!=0)
		{
			printstack();
			k--;
		}
		for(i=0;i<10;i++)
			dfs(temp->children[i]);
		start--;
	}			
}

int main()
{
	int i,j,k,tc,n,m,a,b,c;
	char string[11];
	scanf("%d",&tc);
	for(i=0;i<tc;i++)
	{
		frees(mytrie);
		mytrie=malloc(sizeof(struct Trie));
		mytrie->val='#';
		for(k=0;k<11;k++)
			mytrie->children[k]=NULL;
		state=0;
		scanf("%d\n",&n);
		for(j=0;j<n;j++)
		{
			scanf("%s", string);
			insert(string);
		}
		//dfs(mytrie);
		if(state==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
