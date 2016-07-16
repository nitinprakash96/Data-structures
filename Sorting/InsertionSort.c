/*
* This iterative program is a sorting method called Insertion sort.
*/


#include<stdio.h>
#include<stdlib.h>

int main() {
	int arr[1000];
	int n, i, j, k, swap;

	printf("Enter the number of elements in the array\n");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++) {
		printf("Enter element %d\n", i + 1);
    		scanf("%d", &arr[i]);
  	}
  
	printf("Insertion sort.\n");
  
	printf("Array before sorting:\n");
  	for(i = 0; i < n; i++)
    		printf("%d\t", arr[i]);
    	
	for(i = 1; i < n; i++) {
        	j = i;
      		while(j > 0 && arr[j] < arr[j - 1]) {
          		swap = arr[j];
        		arr[j] = arr[j - 1];
          		arr[j - 1] = swap;
        		j--;
        	}
      
		printf("\nAfter Iteration %d\n", i);
      		for(k = 0; k < n; k++)
        		printf("%d\t", arr[k]);
    	}

	printf("\nArray after sorting:\n");
  	for(i = 0; i < n; i++)
    		printf("%d\t", arr[i]);
  
return 0;
}
