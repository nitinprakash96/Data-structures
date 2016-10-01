/*
	Array implementation then traversal using math logics
*/
#include<stdio.h>
#include<stdlib.h>
int a[100]={0};
int count=0;
void insert()
{
    
    printf("Enter number: ");
    int in;
    scanf("%d",&in);
    a[count++]=in;
}

void del()
{
    int num;
    scanf("%d",&num);
    for(int i=0; i<count; i++)
    {
        if(a[i]==num)
        {
            count--;
            a[i]=a[count];
            a[count]=0;
            break;
        }
    }
}

void search()
{
    int num,flag=0;
    printf("Enter number to be searched: ");
    scanf("%d",&num);
    for(int i=0; i<count; i++)
        if(a[i]==num)
        flag=1;
        
        if(flag)
            printf("Found");
            else
                printf("Not found");
}

void inorder(int x)
{
    int i,j;
    i=2*x+1;
    if(a[i]!=0)
        traverse(i);
    printf("%d",a[x]);
    j=2*x+2;
    if(a[j]!=0)
        traverse(j);
}

int main()
{
    int in;
    do
    {
        system("cls");
        printf("1.Insert element\n2.Delete element\n3.Search element\n4.Traverse tree\n");
        scanf("%d",&in);
        switch(in)
        {
            case 1: insert(); break;
            case 2: del(); break;
            case 3: search();break;
            case 4: inorder(0); getch(); break;
        }
    }while(in!=-1);
    return 0;
}
