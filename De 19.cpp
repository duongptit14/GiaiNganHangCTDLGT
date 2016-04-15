#include<iostream>
#include<malloc.h>
#include<fstream>
#include<cmath>
using namespace std;
fstream fp1;
ofstream fp2;
void taofile()
{
	fp1.open("DATA1.in");
	fp2.open("Ketqua.out");
}
int t,a[10000],n,m,T=1;
int ngto(int x)
{
	while(x<2) return 0;
	for(int i=2;i<=sqrt(x);i++)
	if(x%i==0) return 0;
	return 1;
}
struct node{
	int info;
	struct node *next;
};
struct queue{
	node *front;
	node *rear;
	long dem;
};
void init(queue &q)
{
	q.front=NULL;
	q.rear=NULL;
	q.dem=0;
}
int Emptynode(queue &q)
{
	if(q.dem==0)
	{
		return 1;
	}
	return 0;
}
node *Makenode(int x)
{
	node *p=(node*) malloc(sizeof(node));
	p->info=x;
	p->next=NULL;
	return p;
}
void push(queue &q,int x)
{
	node *p=Makenode(x);
	if(Emptynode(q))
	{
		q.front=p;
		q.rear=p;
	}
	else
	{
		q.rear->next=p;
		q.rear=p;
	}
	q.dem++;
}
int pop(queue &q)
{
	int m=q.front->info;
	if(q.dem==1)
	{
		init(q);
	}
	else
	{
		q.front=q.front->next;
		q.dem--;
	}
	return m;
}
int chuaxet[10000]={0},u=1,truoc[10000];
int ktra(int m,int n)
{
	int dem=0;
	while(m>0)
	{
		if(m%10==n%10) dem++;
		m=m/10;
		n=n/10;
	}
	if(dem==1) return 1;
	return 0;
}
void BFS(int n,int m)
{
	int kt=1,dem=0;
	queue q;
	init(q);
	push(q,n);
	chuaxet[n]=1;
	while(kt!=0)
	{
		int s=pop(q);
		dem++;
		for(int i=1;i<=u;i++)
		{
			
			if(ktra(a[i],s)==1&&chuaxet[a[i]]==0)
			{
				if(a[i]==m)
			{
				kt=0;
				break;
			}
			else
			{
			
				push(q,a[i]);
				chuaxet[a[i]]=1;
		}
			}
		}
		if(kt==0)
		{
			break;
		}
	}
	fp2<<dem<<'\n';
	cout<<dem<<'\n';
}
int main(void)
{
	taofile();
	fp1>>t;
	for(int i=1000;i<=9999;i++)
	{
		if(ngto(i))
		{
			a[u]=i;
			u++;
		}
	}
	while(T<=t)
	{
		fp1>>n>>m;
		BFS(n,m);
		chuaxet[10000]={0};
		T++;
	}
	return 0;
}
