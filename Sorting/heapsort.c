#include<stdio.h>

int main()
{
	int size, i, j, c, root;
	printf("Enter size of elements : ");
	scanf("%d", &size);
	int heap[size];
	printf("Enter the values of the array : ");
	for (i = 0;i < size;i++)
	{
		scanf("%d", &heap[i]);
	}
	int temp;
	for (i = 1;i < size;i++)
	{
		c = i;
		do
		{
			root = (c - 1) / 2;             
			if(heap[root] < heap[c])
			{
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} 
		while(c != 0);
	}
	for (j = size - 1; j >= 0; j--)
	{
		temp = heap[0];
		heap[0] = heap[j];
		heap[j] = temp;
		root = 0;
		do
		{
			c = 2 * root + 1;
			if ((heap[c] < heap[c + 1]) && c < j-1)
			{
				c++;
			}
			if (heap[root]<heap[c] && c<j)
			{
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		}
		while (c < j);
	} 
	printf("The sorted array is : ");
	for (i = 0; i < size; i++)
	{
		printf("%d ", heap[i]);
	}
	printf("\n");
	return 0;
}
