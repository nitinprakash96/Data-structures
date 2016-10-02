/*
 *
 * Manacher’s Algorithm – Linear Time Longest Palindromic Substring
 *
 */

//Manacher Algo to find length of the largest palindromic Substring
//O(2*n)

#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxlenstr = 1e5+7;

inline string Preprocess(string s)
{
	int len = s.length();
	if(len == 0)
		return "^#";
	string ans = "^";
	for(int i = 0; i < len; i++)
		ans += "#" + s.substr(i,1);
	ans += "#$";
	return ans;
	// length of the processes string ans becomes = 2 + len+1 + len = 2*len+3
}
int llpc[3*maxlenstr];
inline string manacher(string str)
{
	string T = Preprocess(str);
	int n = T.length();
	int c = 0 , r = 0;

	for(int i = 1; i <= n; i++)
	{
		int i_mirror = c - (i-c);
		llpc[i] = (r > i) ? min(r-i,llpc[i_mirror]) : 0;
		//extend palindrome around i

		while((i+1+llpc[i]) <= n && (i-1-llpc[i]) >= 0 &&  T[i+1+llpc[i]] == T[i-1-llpc[i]])
			llpc[i]++;

		//adjust the center based on the expanded palindrome
		if(i + llpc[i] > r)
		{
			c = i;
			r = i + llpc[i];
		}
	}

	int maxLen = 0;
	int centerIndex = 0;
	for(int i = 0; i <= n; i++)
	{
		if(llpc[i] > maxLen)
		{
			maxLen = llpc[i];
			centerIndex = i;
		}
	}
	//    ^#a#b# c#d#c #e#f^
	return str.substr((centerIndex-maxLen-1)/2 , maxLen);
	// if only maxlen is needed then return maxLen;
}
//returns the longest palindromic substring
int main()
{

	string input; cin >> input;
	
	string output = manacher(input);

	cout << output << "\n";
	

	return 0;
}

