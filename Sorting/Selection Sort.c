#include<stdio.h>
#include<stdlib.h>

int main() {
	int n, arr[n];
	int i, j, temp, z;

	printf("Enter the number of elements in the array\n");
  	scanf("%d", &n);

  	for(i = 0; i < n; i++) {
      		printf("Enter element> ");
    		scanf("%d", &arr[i]);
  	}

  	printf("Array before sorting:\n");
  	for( i = 0; i < n; i++)
    		printf("%d\t", arr[i]);
  
  	printf("\n");
  	for(i = 0; i < n - 1; i++) {
		for(j = i + 1; j < n; j++) {
			if(arr[i] > arr[j]) {
         			temp = arr[i];
       				arr[i] = arr[j];
       				arr[j] = temp; 
     			}
    		}

		printf("After Iteration %d\n", i + 1);
		for(z = 0; z < n; z++)
      			printf("%d\t", arr[z]);
    		printf("\n");
  	}

	printf("Array after sorting:\n");
	for(i = 0; i < n; i++)
		printf("%d\t", arr[i]);
	printf("\n");

return 0;
}
