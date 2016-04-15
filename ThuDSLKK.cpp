#include<iostream>
using namespace std;
typedef struct TU{
	string tu;
	int solan;
}TU;
typedef struct node{
	TU info;
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
	p=new(struct node);
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
	p->info=x;
	if(Emptynode(plist))
	{
		return -1;
	}
	q=*plist;
	if(p->info.tu<q->info.tu)
	{
		return 0;
	}
	int dem=0;
	while(p->info.tu>q->info.tu)
	{
		dem++;
		q=q->next;
		if(q==NULL)
		{
			break;
		}
	}
	return dem;
}
start insertnode(start *plist,TU x)
{
	int pos=possion(plist,x);
	start p,q,r;
	p=Getnode();
	q=Getnode();
	r=Getnode();
	p->info=x;
	if(pos==-1)
	{
		p->next=NULL;
		p->prew=NULL;
		*plist=p;
		return p;
	}
	else if(pos==0)
	{
		p->next=*plist;
		p->prew=NULL;
		*plist=p;
		return p;
	}
	else
	{
		cout<<pos<<'\n';
		q=*plist;
		int dem=0,kt=0;
		while(dem<pos)
		{
			dem++;
			r=q;
			q=q->next;
			if(q==NULL)
			{
				kt=1;
				break;
			}
		}
		if(kt==1)
		{
			r->next=p;
			p->next=NULL;
			p->prew=r;
			return p;
		}
		else
		{
		
		p->next=r->next;
		p->next->prew=p;
		p->prew=r;
		r->next=p;
		return p;}
	}
}
void searchnode(start *plist,TU x)
{
	start p;
	p=Getnode();
	p=*plist;
	int kt=0;
	while(p!=NULL)
	{
		if(p->info.tu==x.tu)
		{
			kt=1;
			p->info.solan++;
			break;
		}
		p=p->next;
	}
	if(kt==0)
	{
		insertnode(plist,x);
	}
}
void display(start *plist)
{
	start p;
	p=Getnode();
	p=*plist;
	while(p!=NULL)
	{
		cout<<p->info.tu<<" "<<p->info.solan<<'\n';
		p=p->next;
	}
	cout<<'\n';
}
int main(void)
{
	start p;
	init(&p);
	TU x;
	int i=1;
	while(i!=0)
	{
		cout<<"Nhap vao tu"<<'\n';
		cin>>x.tu;
		x.solan=1;
		searchnode(&p,x);
		cout<<"Muon nhap tiep ko"<<'\n';
		cin>>i;
		if(i==0) break;
	}
	display(&p);
	return 0;
}
