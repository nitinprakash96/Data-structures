/*input
AABAACACACAADAABAAABAA AABAAC
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define _ ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
#define mod 1000000000+7
#define limit 100000+5
#define characters 256

void transitional_function(string pattern, ll TF[][characters]){
	ll i, lps =0, x;
	
	// Fill first entries
	for(x =0;x<characters;x++){
		TF[0][x] =0;
	}
	TF[0][pattern[0]] =1;

	// Fill entries in other rows
	for(i =1;i<=pattern.length();++i){
		for(x =0;x<characters;x++){
			TF[i][x] =TF[lps][x];
		}
		if(i == pattern.length())
			break;
		TF[i][pattern[i]] =i+1;
		if(i<pattern.length())
			lps =TF[lps][pattern[i]];
	}
}
void finite_automaton_matcher(string text, string pattern){
	ll TF[pattern.length()+1][characters];
	transitional_function(pattern, TF);
	ll i, q =0;
	for(i =0;i<text.length();++i){
		q =TF[q][text[i]];
		if(q == pattern.length()){	
			cout<<"YES"<<"\n";
			return;
		}
	}
}
int main()
{	_;
	string text, pattern;
	cin>>text>>pattern;
	finite_automaton_matcher(text, pattern);
return 0;
}
