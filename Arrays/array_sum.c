/*
* This program adds two arrays contatining same number of elements.
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
	int n, i;

	printf("Enter the numbetr of elements in the array> ");
	scanf("%d", &n);

	int a[n], b[n];

	printf("Enter the elements for the first array> \n");
	for(i = 0; i < n; i++) {
		printf("Enter element %d> ", i + 1);
		scanf("%d", &a[i]);
	}
	
	printf("Enter the elements of second array> \n");
	for(i = 0; i < n; i++) {
		printf("Enter element %d> ", i + 1);
		scanf("%d", &b[i]);
		a[i] += b[i];
	}

	printf("Sum of the two array is> ");
	for(i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n");
  
return 0;
}
