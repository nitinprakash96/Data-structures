/*input
2
abcba
banananopaop
*/
#include<bits/stdc++.h>
using namespace std;
// Building of Longest Prefix Array which is a Suffix also
vector<int> prefix_and_suffix(string pattern)
{	vector<int> lps(pattern.length());
	int index =0; lps[0] =0;
	for(int i =1;i<pattern.length();)
	{	if(pattern[i] == pattern[index])
			lps[i++] =(index++)+1;
		else
		{	if(index!=0)
				index =lps[index-1];
			else
				lps[i++] =0;		
		}
	}
	return lps;
}
// Checking of pattern whether it is present in Text or not in O(text.length)
void KMP(string text, string pattern)
{	vector<int> lps =prefix_and_suffix(pattern);
	int i =0, j =0;
	while(i<text.length() && j<pattern.length())
	{	if(text[i] == pattern[j])
		{	i++;
			j++;
		}
		if(j == pattern.length())
		{	cout<<"Yes"<<endl;
			return;
			j =lps[j-1];
		}
		else if(i<text.length() && pattern[j]!=text[i])
		{	if(j!=0)	
				j =lps[j-1];
			else
				i++;
		}
	}
	cout<<"Not Possible\n";
}

int main()
{	string text, pattern;
	cin>>pattern>>text;
	if(pattern.length()>text.length())
		cout<<"Not Possible\n";
	else
		KMP(text, pattern);
return 0;
}
