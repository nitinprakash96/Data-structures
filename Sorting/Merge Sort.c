#include<stdio.h>
#include<stdlib.h>

void mergesort(int a[], int l, int r);

int main() {
	int n, i;
	
	printf("How many elements> ");
		scanf("%d", &n);
	
	int a[n];

	for(i = 0; i < n; i++) {
		printf("Enter element> ");
		scanf("%d", &a[i]);
	}

	printf("Sorted array> ");

	mergesort(a, 0, n - 1);

	for(i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n");
return 0;
}

void merge(int a[], int l, int m, int r) {

	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int la[n1], ra[n2];
  
	for(i = 0; i < n1; i++)
		la[i] = a[l + i];
	for(j = 0; j < 2; j++)
		ra[j] = a[m + 1 + j];
	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2) {   
		if (la[i] <= ra[j]) {
		a[k] = la[i];
          		i++;
      		} else {
			a[k] = ra[j];
			j++;
		}
		k++;
	}

}

void mergesort(int a[], int l, int r) {
	if (l < r) {
		int d;
		int m = l + (r - l) / 2;
    		mergesort(a, l, m);
    		mergesort(a, m + 1, r);
    		merge(a, l, m, r);

  	}	
}
