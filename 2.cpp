#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct TNode
{
	char data;
	TNode *lchild,*rchild;
}*BiTree;
BiTree p;

void creat(BiTree &T,char data)
{
	if(T==NULL)
	{
		T=new TNode;
		T->lchild=NULL;
		T->rchild=NULL;
		T->data=data;
	}
	else if(data<T->data)
		creat(T->lchild,data);
	else if(data>T->data)
		creat(T->rchild,data);
}
void search(BiTree T,char m)
{
	if(T!=NULL)
	{
       if(T->data==m)
	   {
		    p=T;
	   }
	   else
	   {
	    search(T->lchild,m);
		 search(T->rchild,m);
	   }
	}
}
int main()
{
	BiTree T;
	T=new TNode;
	T->lchild=NULL;
	T->rchild=NULL;
	cin>>T->data;
	getchar();
	while(1)
	{
		char ch;
		scanf("%c",&ch);
		if(ch=='\n')break;
		else if(ch!=' ')
			creat(T,ch);
	}
	char m;
	cin>>m;
	p=new TNode;
	search(T,m);
	BiTree a[100];
	a[0]=T;
	int k1=0,k2=1,i,kk=1;
	int flag=0;
	if(a[0]->data==m)
		{
			cout<<"1";
			flag=1;
	}
	else
	{
	  while(1)
	  {
		for(i=k1;i<k2;i++)
		{
			if(a[i]->lchild!=NULL)
			{
				a[kk]=a[i]->lchild;
				if(a[kk]->data==m)
					{
						cout<<kk+1;
						flag=1;
						break;
				    }
				kk++;
			}
			if(a[i]->rchild!=NULL)
			{
				a[kk]=a[i]->rchild;
				if(a[kk]->data==m)
					{
						cout<<kk+1;
						flag=1;
						break;
				    }
				kk++;
			}
		}
		if(flag==1)break;
		k1=k2;
		k2=kk;
		if(k1==k2)break;
	  }
	}
	if(flag==0)cout<<"0";
}


