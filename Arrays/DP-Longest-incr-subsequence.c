#include <stdio.h>
#include <math.h>


int main(int argc, char **argv)
{
    int n;
    scanf("%d",&n);
    int a[n],LS[n];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    for(int i=0; i<n; i++)
    {
        LS[i]=1;
        for(int j=0; j<i; j++)
            if(a[i]>a[j] && LS[i]<=LS[j])
                LS[i]=LS[j]+1;
    }    
    int max=0;
    
    for(int i=0; i<n; i++)
        printf("%d ",LS[i]);
        printf("\n");
    for(int i=0; i<n; i++)
        if(LS[i]>=max)
            max=LS[i];
    printf("%d",max);    
    
    
	return 0;
}
