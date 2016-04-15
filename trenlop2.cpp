#include<iostream>
#include<string>
using namespace std;
typedef struct TU{
	string tu;
	int solan;
}TU;
typedef struct node{
	TU infor;
	struct node *next;
	struct node *prew;

}*start;
void init(start *plist)
{
	*plist=NULL;
}
start Getnode(void)
{
	start p;
	p= new(struct node);
	return p;
}
int Emptynode(start *plist)
{
	if(*plist==NULL) return 1;
	return 0;
}
int possion(start *plist,TU x)
{
	start p,q;
	p=Getnode();
	q=Getnode();
	if(Emptynode(plist))
	{
		return 0;
	}
	p=*plist;
	int dem=0;
	while(p!=NULL)
	{
		dem++;
		if(p->infor.tu>x.tu)
		{
			return dem;
		}
		p=p->next;
	}
	
	return dem+1;
	
}
start insertpos(start *plist,TU x)
{
	start p,q,r;
	p=Getnode();
	q=Getnode();
	r=Getnode();
	p->infor=x;
	if(Emptynode(plist))
	{
		*plist=p;
		p->next=NULL;
		p->prew=NULL;
		return p;
	}
	q=*plist;
	if(possion(plist,x)==1)
	{
		p->next=*plist;
		p->prew=NULL;
		*plist=p;
		return p;
	}
	int t=possion(plist,x),dem=0;
	while(q!=NULL)
	{
		dem++;
		r=q;
		q=q->next;
	}
	
	if(t>dem)
	{
		r->next=p;
		p->prew=r;
		p->next=NULL;
		return p;
	}
	q=*plist;
	for(int i=1;i<t;i++)
	{
		r=q;
		q=q->next;
	}
	p->next=r->next;
	p->next->prew=p;
	r->next=p;
	p->prew=r;
	return p;
	
}
void searchnode(start *plist,TU x)
{
	start p;
	p=Getnode();
	p=*plist;
	int kt=0;
	while(p!=NULL)
	{
		if(p->infor.tu==x.tu)
		{
			kt=1;
			p->infor.solan++;
			break;
		}
		p=p->next;
	}
	if(kt==0)
	{
		insertpos(plist,x);
	}
}
void display(start *plist)
{
	start p,q;
	p=Getnode();
	q=Getnode();
	p=*plist;
	q=*plist;
	int dem=0;
	while(q!=NULL)
	{
		dem++;
		q=q->next;
	}
	cout<<dem<<'\n';
	while(p!=NULL)
	{
		cout<<p->infor.tu<<" "<<p->infor.solan<<'\n';
		p=p->next;
	}
}
int main(void)
{
	start plist;
	init(&plist);
	TU x;
	int i=0;
	while(i!=1)
	{
		cin>>x.tu;
		x.solan=1;
		searchnode(&plist,x);
		cout<<"Ban co muon nhap nua ko"<<'\n';
		cin>>i;
		if(i==1) break;
	}
	display(&plist);
	return 0;
}
