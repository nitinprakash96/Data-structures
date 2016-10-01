#include<stdio.h>
#include<string.h>

int mark[100000]={0},count[100000]={0},rank[100000]={0},AA[100000]={0},ans[100000]={0},anscount=0;

int funct(const void * a, const void * b) //For qsort function
{
	   return ( *(int*)a - *(int*)b );
}

long long int findd(long long int i)
{
	if(AA[i]!=i)
		AA[i]=findd(AA[i]);
	return AA[i];
}

void unions(long long int a, long long int b)
{
	long long int aa=findd(a);
	long long int bb=findd(b);
	if(rank[aa]>rank[bb])
	{
		AA[bb]=aa;
		count[aa]+=count[bb];
	}
	if(rank[bb]>rank[aa])
	{
		AA[aa]=bb;
		count[bb]+=count[aa];
	}
	else if(rank[bb]==rank[aa])
	{
		AA[aa]=bb;
		rank[bb]++;
		count[bb]+=count[aa];
	}
}

int main()
{
	int a,b,c,i,j,k,n,q;
	scanf("%d", &n);
	scanf("%d", &q);
	for(i=0;i<=n;i++)
	{
		AA[i]=i;
		count[i]=1;
	}
	for(i=0;i<q;i++)
	{
		scanf("%d", &a);
		scanf("%d%d", &b, &c);
		if(a==1)
			unions(b,c);
		if(a==2)
		{
			if(findd(b)==findd(c))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	int counts=0;
	for(i=1;i<=n;i++)
	{
		if(count[findd(i)]>0 && mark[findd(i)]==0)
		{
			mark[findd(i)]=1;
			counts++;
			ans[anscount++]=count[findd(i)];
		}
	}
	qsort(ans, anscount, sizeof(int), funct);
	printf("%d\n", counts);
	for(i=0;i<anscount;i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
