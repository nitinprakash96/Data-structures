/*
	Program for counting sort
*/

#include <stdio.h>

#define N 9 
using namespace std;

void counting(int a[])
{
    int count[9]={0};
    int out[9]={0};
    for(int i=0; i<9; i++)
        ++count[a[i]];
    
    for(int i=1; i<9; i++)
        count[i]+=count[i-1];
        
    for(int i=0; i<9; i++)
    {
        //because the first number will have count of 1 and we need to 
        //make it 0 in order to correctly fit inside sorted array.
        out[count[a[i]]-1]=a[i];
        --count[a[i]];
    }
    for(int i=0; i<9; i++)
        printf("%d ",out[i]);
}

int main()
{
    //Make a predefined array or let the user enter themselves
    int a[]={1,4,2,5,8,5,2,2,6};
    counting(a);
}
