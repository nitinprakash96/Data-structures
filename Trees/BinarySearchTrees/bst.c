#include<stdio.h>
#include<stdlib.h>

struct Node{
    int val;
    struct Node* left;
    struct Node* right;
};

struct Queue{
    struct Node* value;
    struct Queue* next;
};

struct Queue* myqueue=NULL;

int state;

struct Node* mytree=NULL;
            
struct Node* delete(struct Node* temp, int x)
{
    if(temp->val==x && temp->left==NULL && temp->right==NULL)
        return NULL;
    else
    {
        if(temp->val==x && temp->left!=NULL)
        {
            struct Node* temp2=temp->left;
            while(temp2->right!=NULL)
                temp2=temp2->right;
            temp->val=temp2->val;
            temp->left=delete(temp->left,temp2->val);
        }
        else if(temp->val==x && temp->right!=NULL)
        {
            struct Node* temp2=temp->right;
            while(temp2->left!=NULL)
                temp2=temp2->left;
            temp->val=temp2->val;
            temp->right=delete(temp->right,temp2->val);
        }
        else if(temp->val>=x)
            temp->left=delete(temp->left,x);
        else if(temp->val<x)
            temp->right=delete(temp->right,x);
        return temp;
    }
}

void preorder(struct Node* temp)
{
    if(temp!=NULL)
    {
        printf("%d ", temp->val);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(struct Node* temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->val);
    }
}

void inorder(struct Node* temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d ", temp->val);
        inorder(temp->right);
    }
}

void checktree(struct Node* temp, int min, int max)
{
    if(temp!=NULL)
    {
        if(temp->val>=min && temp->val<=max)
        {
            checktree(temp->left,min,temp->val);
            checktree(temp->right,temp->val+1,max);
        }
        else
            state=1;  
    }
}

int find(int x)
{
    struct Node* temp=mytree;
    while(temp!=NULL)
    {
        if(temp->val==x)
            return 1;
        if(temp->val<x)
            temp=temp->right;
        else
            temp=temp->left;
    }
    return 0;
}

void insert(int x)
{
    struct Node* temp=mytree;
    struct Node* temp2=malloc(sizeof(struct Node));
    temp2->left=NULL;
    temp2->right=NULL;
    temp2->val=x;
    if(mytree==NULL)
    {
        mytree=temp2;
    }
    else
    {
        while(1)
        {
            if(temp->val>=x && temp->left==NULL)
            {
                temp->left=temp2;
                break;
            }
            else if(temp->val<x && temp->right==NULL)
            {
                temp->right=temp2;
                break;
            }
            else if(temp->val>=x)
                temp=temp->left;
            else
                temp=temp->right;
        }
    }
    return;
}

int main()
{
    int x,y,z;
    scanf("%d", &x);
    while(x!=6)
    {
        if(x==1)
        {
            scanf("%d", &y);
            insert(y);
        }
        if(x==2)
        {
            scanf("%d", &y);
            printf("%d\n", find(y));
        }
        if(x==3)
        {
            inorder(mytree);
            printf("\n");
        }
        if(x==4)
        {
            preorder(mytree);
            printf("\n");
        }
        if(x==5)
        {
            postorder(mytree);
            printf("\n");
        }
        if(x==7)
        {
            scanf("%d", &y);
            mytree=delete(mytree,y);
        }
        if(x==8)
        {
            state=0;
            checktree(mytree,-100000000,1000000000);
            if(state==0)
                printf("Its a tree\n");
            else
                printf("Its not a tree\n");
        }
        scanf("%d", &x);
    }
    return 0;
}
