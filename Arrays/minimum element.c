/*
* This program finds out the lowest number in the array.
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
	int i, n, lo;

	printf("Enter the number of elements> ");
	scanf("%d", &n);
	
	int a[n];

	for(i = 0; i < n; i++) {
		printf("Enter element> ");
		scanf("%d", &a[i]);
	}

	lo = a[0];

	for(i = 0; i < n; i++)
		if (lo > a[i]) lo = a[i];

	printf("\n%d is the minimum element in the array\n", lo);
  
return 0;
}
