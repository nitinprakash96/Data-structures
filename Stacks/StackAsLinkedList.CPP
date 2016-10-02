#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>

struct node
{
 int data;
 node *next;
};

class stack
{
 node *top;
 public:
 stack()
 {
  top=NULL;
 }
 void push(int item)
 {
  node *p=new node;
  if(p==NULL)
  {
   cout << "Stack full";
  }
  else
  {
  p->data=item;
  p->next=top;
  top=p;
  cout << "Data entered: " << top->data << endl;
  }
 }
 void pop()
 {
  if(top==NULL)
  cout << "Stack is empty" << endl;
  else{
  node *t=top;
  cout << t;
  cout << "Delete data: " << top->data << endl;
  top=t->next;
  delete t;

  }
 }
};
void main()
{
stack obj;
obj.push(10);
obj.push(11);
obj.pop();
obj.pop();
obj.pop();
getch();
}
