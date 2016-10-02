#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{

	//taking input n, number of elements
	int n;
	cin>>n;
	int logn=log(n);

	//taking input the elements of array
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	//building sparse table, time complexity: O(nlog(n)), space complexity: O(nlog(n))
	//x[i][j] is the minimum value in subarray of length 2^j starting from index i.
	int x[n][logn];
	for(int j=0;j<n;j++){
		for(int i=0;i+(1<<j)-1<n;i++){
			if(j==0)x[i][j]=a[i];
			else x[i][j]=min(x[i][j-1],x[i+(1<<(j-1))][j-1]);
		}
	}

	//querying from sparse table, time complexity per query: O(1)
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int left,right;
		cin>>left>>right;
		int dist=right-left+1;
		int logdist=log(dist);
		cout<<min(x[left][logdist],x[right+1-(1<<logdist)][logdist])<<endl;
	}

	return 0;
}