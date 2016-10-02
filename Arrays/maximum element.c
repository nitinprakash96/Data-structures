/*
* This program finds out the highest number in a given array.
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
	int n, i, hi;
	
	printf("Enter the number of elements in the array> ");
	scanf("%d", &n);

	int a[n];
	
	for(i = 0; i < n; i++) {
		printf("Enter element> ");
		scanf("%d", &a[i]);
	}

	hi = a[0];

	for(i = 0; i < n; i++) {
		if(hi < a[i])
		hi = a[i];
	}

	printf("\n%d is the maximum element in the array\n", hi);
  
return 0;
}
