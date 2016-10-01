#include<stdio.h>

int bit[100000]={0}; //Start from the first index
int n;

//This is point update and range query
//Stores cumilative sum

void change(int index, int val)
{
	while(index<=n)
	{
		bit[index]+=val;
		index+=index&((-1)*index);
	}
}

int query(int range)
{
	int ans=0;
	while(range>0)
	{
		ans+=bit[range];
		range-=range&((-1)*range);
	}
	return ans;
}

int main()
{
	int i,j,k,m,a,b;
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		scanf("%d", &a);
		change(i,a);
	}
	scanf("%d", &m);
	for(j=1;j<=m;j++)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", query(b)-query(a-1)); //query of a includes a as well, we dont want to include that vertex as we want sum from a (inclusive of a) till b
	}
	return 0;
}
