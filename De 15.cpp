#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
	fstream fp1;
	ofstream fp2;
	ofstream fp3;
	ofstream fp4;
void taofile()
{
	fp1.open("DATA1.in");
	fp2.open("ketqua1.out");
	fp3.open("Ketqua2.out");
	fp4.open("Ketqua3.out");
}
typedef struct SO{
	int so;
	int solan;
}SO;
typedef struct node{
	SO info;
	struct node *next;
}*start;
void init(start *plist)
{
	*plist =NULL;
}
start Getnode(void)
{
	start p;
	p=new(struct node);
	return p;
}
int Emptynode(start *plist)
{
	if(*plist==NULL)
	{
		return 1;
	}
	return 0;
}
start insertbottom(start *plist,SO x)
{
	start p,q;
	p=Getnode();
	q=Getnode();
	p->info=x;
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
void Searchnode(start *plist,SO x)
{
	start p;
	p=Getnode();
	p=*plist;
	int kt=0;
	while(p!=NULL)
	{
		if(p->info.so==x.so)
		{
			p->info.solan++;
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
int ngto(int n)
{
	int i;
	while(n<2) return 0;
	for(i=2;i<=sqrt(n);i++)
	if(n%i==0) return 0;
	return 1;
}
int thuannghich(int n)
{
	int dao=0,m=n;
	while(n>0)
	{
		dao=dao*10+n%10;
		n=n/10;
	}
	if(dao==m) return 1;
	return 0;
}
int main()
{
	start p;
	init(&p);
	taofile();
	SO x;
	while(!fp1.eof())
	{
		fp1>>x.so;
		x.solan=1;
		Searchnode(&p,x);
	}
	while(p!=NULL)
	{
		if(thuannghich(p->info.so)&&ngto(p->info.so))
		{
			fp4<<p->info.so<<" "<<p->info.solan;
			fp4<<'\n';
		}
		else if(thuannghich(p->info.so))
		{
			fp3<<p->info.so<<" "<<p->info.solan;
			fp3<<'\n';
		}
		else if(ngto(p->info.so))
		{
			fp2<<p->info.so<<" "<<p->info.solan;
			fp2<<'\n';
		}
		p=p->next;
	}
	return 0;
}
