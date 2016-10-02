/*
* Linear search algorithm implementation
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
	int search, n, i;
	int flag = 0;

	printf("Enter the number of elements in the array> ");
	scanf("%d", &n);

	int arr[n];

	for(i = 0; i < n; i++) {
		printf("Enter element %d> ", i + 1);
		scanf("%d", &arr[i]);
	}

	printf("Enter the number to be searched> ");
	scanf("%d", &search);

	for(i = 0; i < n; i++) {
		if(arr[i] == search) {
			flag = 1;
			break;
		}
	}

	if (flag == 1) printf("%d is present in the array\n", search);
	else printf("%d is not present in the array\n", search);

return 0;
}
