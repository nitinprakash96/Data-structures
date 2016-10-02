/*

To find a number is power of 2 or not in O(1) time.

*/

#include <iostream>
using namespace std;

bool isPowerOfTwo(int);

int main(){

  int n;
  cout<<"Enter number to check it is power of two or no : ";
  cin>>n;

  if(isPowerOfTwo(n) == true)
    cout<<"Yes, It is power of 2"<<endl;
  else
    cout<<"No, It is not power of 2"<<endl;

}

bool isPowerOfTwo(int n){

  /*
  Example : n   = 4 and in binary n   = 0100
            n-1 = 3 and in binary n-1 = 0011

            n & (n-1) : 0100 & 0011 = 0

  */
  int res = n&(n-1);

  if( res == 0 )
    return true;
  else
    return false;

}
