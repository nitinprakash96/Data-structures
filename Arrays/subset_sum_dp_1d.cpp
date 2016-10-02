// 1d saves memory O(sum).

/*
 * Dynamic Programming | (Subset Sum Problem)
 *
 */
#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;


bool is_subset_sum (vector<int>& v,int sum)
{
	int n=v.size();

	vector<int> dp(sum+1,0);

	dp[0]=1; //sum =0 is always attainable.

	for(int i = 0; i<n; i++)
	{
		for(int j = sum; j >= v[i]; j--)
		{
			dp[j] |= dp[j-v[i]];
		}
	}

	return dp[sum];
	//dp[i] = 1 if we can make sum = i
	// if sum of all array ele < desired sum then 0. 
}

int main()
{

	int n; cin >> n;
	vector<int> input(n);
	for(int i = 0; i < n; i++)
		cin >> input[i];
	int num_to_check; 
	cin >> num_to_check;
	cout << is_subset_sum(input, num_to_check) << "\n";

	return 0;
}
