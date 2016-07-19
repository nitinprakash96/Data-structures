/*
* This program sums up the even and odd numbers in an array.
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
	int n, i;
	int sum_even = 0, sum_odd = 0;

	printf("Enter the number of elements in array> ");
	scanf("%d", &n);

	int arr[n];

	for(i = 0; i < n; i++) {
		printf("Enter element %d>", i + 1);
		scanf("%d", &arr[i]);
		
		if (arr[i] % 2 == 0) sum_even = sum_even + arr[i];
		else sum_odd = sum_odd + arr[i];
	}

	printf("The sum of the even numbers in the array is %d\n", sum_even);
	printf("The sum of the odd numbers in the array is %d\n", sum_odd);
return 0;
}
