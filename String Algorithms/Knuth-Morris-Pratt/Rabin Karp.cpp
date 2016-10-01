/*input
1
Rabinkarp p
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define _ ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
#define mod 1000000007
#define limit 100000+5
ll int_mod(ll a, ll b)
{	return (a%b+b)%b;	//calculates even for negative
}
ll power(ll base, ll m, ll mo)
{	ll result =1;
	base =base%mo;
	while(m > 0)
	{	if(m&1)	result =(result*base)%mo;
		m =m>>1;
		base =(base*base)%mo;
	}
	return result;
}
bool Rabin_Karp(string text, string pattern)
{	if(text.length()<pattern.length())		return false;
	ll j, i, hp =0, ht =0, Base =256;
	ll h =power(Base, pattern.length()-1, mod);
	// hash value of pattern and first segment of text of Pattern length
	for(i =0;i<pattern.length();++i)
	{	hp =int_mod(hp * Base + pattern[i], mod);
		ht =int_mod(ht*Base + text[i], mod);
	}
	for(i =pattern.length();i<text.length()+1;++i)
	{	if(ht == hp)
		{	//check for Spurious Hits
			for(j =0;j<pattern.length();)
			{	if(pattern[j] == text[i+j])
					++j;
				else
					return true;
			}
		}
		//t[s+1] = 10(t[s] -10^m-1*T[s+1]) + T[s+m+1]
		ht =int_mod(ht - int_mod(text[i-pattern.length()]*h,mod),mod);
		ht =int_mod(ht*Base,mod);
		ht =int_mod(ht+text[i],mod);
	}
	return false;
}	

int main()
{	_;
	int t;
	cin>>t;
	while(t--)
	{	string text, pattern;
		cin>>text>>pattern;
		if(Rabin_Karp(text, pattern))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
return 0;	
}
