#include <stdio.h>
#define BUCKETS 100
using namespace std;

void BucketSort(int a[],int size){
	int i,j,k;
	int buckets[BUCKETS];
	
	for(j=0;j<BUCKETS;j++)
	    buckets[j] = 0;
	    
	for(i=0;i<size;i++)
	    ++buckets[a[i]];
	    
	for(i=0,j=0;j<BUCKETS;j++)
	    for(k=buckets[j];k>0;--k)
	        a[i++] = j;
	
	for(int i=0;i<size;i++)
	printf("%d ",a[i]);
	
}

int main() {
	int arr[10000];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&arr[i]);

	BucketSort(arr,n);
	
	return 0;
}