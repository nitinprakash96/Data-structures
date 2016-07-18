/*
* Selection Sort Algorithm implementation
*/

#include<stdio.h>
#include<stdlib.h>

void selectionsort(int a[], int n);

int main() {
	int n, i;
	
	printf("How many elements> ");
		scanf("%d", &n);
	
	int a[n];

	for(i = 0; i < n; i++) {
		printf("Enter element> ");
		scanf("%d", &a[i]);
	}

	printf("Sorted array> ");

	selectionsort(a, i);

	for(i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n");
return 0;
}


void selectionsort(int a[], int n)
{
	int i, j, p, tp, min;

	for (i = 0; i < n; i++)
	{
		min = a[i];
		p = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < min) 
			{
				min = a[j];
				p = j;
			}
		}
		if (p != i)
		{
			tp = a[i];
			a[i] = a[p];
			a[p] = tp;
		}
	}
}
