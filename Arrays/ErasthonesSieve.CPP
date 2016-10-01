#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

void mark(int a[], int div, int n)
{
    for(int i=1; i*div<= n; i++)
        a[i*div]=1;
}

int main() 
{
/* Enter your code here. Read input from STDIN. Print output to STDOUT */   
int n;
cin >> n;
int p[n+1]={0};
for(int i=2; i<=(n) ; i++)
{
    //cout << i << " " << p[i] << endl;
    if(p[i]==0){
    mark(p,i,n);
    cout << i << " ";
    }
}
return 0;
}
    

