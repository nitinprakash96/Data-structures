/*
 *
 * Dynamic Programming | (Longest Common Subsequence)
 *
 *
 * O(n*m) complexity , can be reduced to O(n*m/wt) where wt is alphabet size (set of char's we can use )
 *
 * where n , m are length of input strings.
 *
 */
#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;

string LCS ( string s , string t )
{
	int len_s =  s.length();
	int len_t = t.length();
	int dp[s.length()+1][t.length()+1];
	// Filling DP table in bottom - up fashion.
	for(int i = 0; i <= len_s; i++)
	{
		for(int j = 0; j <= len_t; j++)
		{
			if ( i == 0 || j == 0 ) 
				dp[i][j] =  0;
			// If last characters of both sequences match.
			else if ( s[i-1] == t[j-1] )
				dp[i][j] = dp[i-1][j-1] + 1;
			//If last characters of both sequences do not match 
			else
				dp[i][j] = max ( dp[i-1][j] , dp[i][j-1] );
		}
	}
	int len_of_lcs = dp[len_s][len_t];
	/*
	 * Will return LCS length 
	 */
	//return dp[len_s][len_t];   //  Use if only length of LCS is required

	string ans;
	ans.resize(len_of_lcs);

	int i = len_s;
	int j = len_t;
	int id = len_of_lcs;

	// backtracking to get the characters in the LCS of two strings.
	while(i > 0 && j > 0)
	{
		// if last characters match then we must can have this in our answer
		if (s[i-1] == t[j-1] )
		{
			ans[id-1] = s[i-1]; 
			id--;
			i--; j--;
		}
		// else continue searching by going from bottom down(len_s,len_t) to top up(0,0)
		else if ( dp[i-1][j] > dp[i][j-1] )
			i--;  
		else j--;
	}
	/*
	 * will return string ( longest commone subsequence ) 
	 */
	return ans;
}

int main()
{

	string input1 , input2;
	cin >> input1 >> input2;

	string answer;
	answer = LCS(input1,input2);

	cout << answer << "\n";

	return 0;
}
