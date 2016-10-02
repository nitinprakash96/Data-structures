#include<bits/stdc++.h>
using namespace std;
// To find the next number of num which is power of 2 
int nextPowerOf2(int num){
        if(num ==0){
            return 1;
        }
        if(num > 0 && (num & (num-1)) == 0){
            return num;
        }
        while((num & (num-1)) > 0){
            num = num & (num-1);
        }
        return num<<1;
    }
int main()
{
      cout<<"Enter any number\n";
      int n;
      cin>>n;
      cout<<"Next power of 2 is-->";
    cout<<nextPowerOf2(n)<<endl;
	return 0;
	}
