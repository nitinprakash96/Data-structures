#include<stdio.h>
#include<stdlib.h>

int main() {
	int n, i, sum = 0;

	printf("Enter the number of elements in the array> ");
	scanf("%d", &n);

	int a[n];

	for(i = 0; i < n; i++) {
		printf("Enter element> ");
		scanf("%d", &a[i]);
		sum = sum + a[i];
	}

	printf("The sum of the elements in the array is %d\n", sum);

return 0;
}
