/*
* Quick Sort algorithm implementation.
*/

#include<stdio.h>
#include<stdlib.h>

void  quicksort(int a[], int low, int high);

int main() {
	int n, i;

	printf("Enter the number of elements in the array> ");
	scanf("%d", &n);

	int a[n];

	for(i = 0; i < n; i++) {
		printf("Enter element %d> ", i + 1);
		scanf("%d", &a[i]);
	}

	quicksort(a, 0, n - 1);

	printf("Array after sorting> \n");
	for(i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n");

return 0;
}


void quicksort(int a[], int low, int high) {
	int p;
	if (low < high) {
		p = partition(a, low, high);

		quicksort(a, low, p - 1);
		quicksort(a, p + 1, high);
	}
}

int partition(int a[], int low, int high) {
	int i, j, p, tp;

	p = a[high];
	i = low - 1;

	for (j = low; j < high; j++) {
		if (a[j] < p) {
			i = i + 1;
			tp = a[j];
			a[j] = a[i];
			a[i] = tp;
		}
	
	}

	a[high] = a[i + 1];
	a[i + 1] = p;

	return i + 1;
}
