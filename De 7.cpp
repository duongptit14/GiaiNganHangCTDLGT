#include<iostream>
#include<cstring>
#include<malloc.h>
#include<fstream>
using namespace std;
using std::cout;
	fstream fp1;
	fstream fp2;
	fstream fp3;
void taofile()
{
	fp1.open("DATA1.in");
	fp2.open("DATA2.in");
	fp3.open("Ketqua.out");
}
typedef struct TU{
	char tu[100];
	float solan;
}TU;
typedef struct node{
	TU infor;
	struct node *next;
}*start;
void init(start *plist)
{
	*plist=NULL;
}
start Getnode(void)
{
	start p;
	p=new(struct node);
	return p;
}
void freenode(start p)
{
	free(p);
}
int Emptynode(start *plist)
{
	if(*plist==NULL)
	return 1;
	return 0;
}
start insertbottom(start *plist,TU x)
{
	start p,q;
	p=Getnode();
	p->infor=x;
	if(Emptynode(plist))
	{
		p->next=NULL;
		*plist=p;
		return p;
	}
	q=*plist;
	while(q->next!=NULL)
	{
		q=q->next;	
	}
	q->next=p;
	p->next=NULL;
	return p;
}
void searchnode(start *plist,TU x)
{
	start p;
	p=*plist;
	int kt=0;
	while(p!=NULL)
	{
		if(strcmp(p->infor.tu,x.tu)==0)
		{
			p->infor.solan++;
			kt=1;
			break;
		}
		p=p->next;
	}
	if(kt==0)
	{
		insertbottom(plist,x);
	}
	
}
void display(start *plist,float n)
{
	start p,q;
	p=Getnode();
	q=Getnode();
	if(Emptynode(plist))
	{
		fp3<<"Khong co gi hien thi";
		return;
	}
	p=*plist;
	q=*plist;
	int dem=0;
	while(q!=NULL)
	{
		dem++;
		q=q->next;
	}
	fp3<<dem<<'\n';
	cout<<dem<<'\n';
	while(p!=NULL)
	{
		fp3.precision(0);
		cout.precision(0);
		fp3<<p->infor.tu<<" "<<p->infor.solan/n;
		cout<<p->infor.tu<<" "<<p->infor.solan/n;
		p=p->next;
		fp3<<'\n';
		cout<<'\n';
	}
	
}
int main(void)
{
	start plist;
	init(&plist);
	taofile();
	TU x;
	float dem=0;
	while(!fp1.eof())
	{
		fp1>>x.tu;
		x.solan=1;
		dem++;
		searchnode(&plist,x);
	}
	while(!fp2.eof())
	{
		fp2>>x.tu;
		x.solan=1;
		dem++;
		searchnode(&plist,x);
	}
	display(&plist,dem);
	return 0;
}
