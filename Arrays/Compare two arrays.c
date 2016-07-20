/*
* This is a program that compare two given arrays
* element by element.
*/
#include<stdio.h>
#include<stdlib.h>

int main() {
	int n, i;
	int c = 0;
	
	printf("Enter the number of elements in the arrays> ");
	scanf("%d", &n);
	
	int a[n], b[n];
	
	printf("Enter the elements of the first array> ");
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);

	printf("Enter the elements of the second array> ");
	for(i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		if (a[i] != b[i])
      			c = 1;
  	}
	
	if (c == 1) printf("No, the arrays are not equal\n");
	else printf("Yes, the arrays are equal\n");
  
return 0;
}
