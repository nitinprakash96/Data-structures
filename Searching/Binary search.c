/*
* Binary search algorithm implementation.
* The position determined by the following search algorithm is 0 indexed.
*/

#include<stdio.h>
#include<stdlib.h>

int BinarySearch(int first,int last,int *a,int x) {
	int mid;

	while(first <= last) {
		// Evrytime we get to the middle position of the most appropriate portion of the array
		mid = (first + last) / 2;
		if(a[mid] < x) {
			first = mid + 1;
          		continue;
    		}
		if(x < a[mid]) {
        		last = mid - 1;
      			continue;
    		}
		else
			return mid;
	}
return -1;  
}

int main() {
	int n, i, j;
	int temp;
	int lower, upper, search;

	printf("Enter the number of elements :\n");
	scanf("%d", &n);

	int arr[n];

 	for(i = 0; i < n; i++) {
		printf("Enter element %d> ", i + 1);
  		scanf("%d", &arr[i]);
	}
  
	printf("Enter the element to be searched :\n");
  	scanf("%d", &search);
  
	lower = 0;
  	upper = n;

	//Sort the unsorted array first using bubble sort  complexity being O(n^2)
   	for(i = 0; i < n; i++) {
      		for(j = i + 1; j < n; j++) {
          		if(arr[i] > arr[j]) {
            			temp = arr[i];
            			arr[i] = arr[j];
            			arr[j] = temp;
          		}
      		}
  	}

	int ans = BinarySearch(lower, upper, arr, search);

	printf("Array after being sorted> ");
	for(i = 0; i< n; i++)
		printf("%d\t", arr[i]);
	printf("\n");

	if (ans == -1)
    		printf("The element %d is not present in the array\n", search);
  	else
    		printf("The element %d is in position %d as 1-based Indexing\n", search, ans+1);
	//to get 0 indexed search replace ans by ans 
  
return 0;
}
