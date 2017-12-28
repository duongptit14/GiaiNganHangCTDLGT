#include<iostream>
#include<fstream>
#define MAX 10000
using namespace std;
fstream fp1;
ofstream fp2;
void taofile()
{
	fp1.open("DATACTDL.in");
	fp2.open("cay.out");
}
struct canh1{
	int t;
	int s;
	int tso;
};
//tao input
int a[10][10],n;
void Floyd(int u)
{
	int p[10][10];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			p[i][j]=j;
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[i][j]>a[i][k]+a[k][j])
				{
					a[i][j]=a[i][k]+a[k][j];
					p[i][j]=p[i][k];
				}
			}
		}
	}
	for(int j=1;j<=n;j++)
	{
		cout<<"khoang cach "<<a[u][j]<<'\n';
		int temp=u;
		while(temp!=j)
		{
			cout<<temp<<"->";
			temp=p[temp][j];	
		} 
		cout<<temp;
		cout<<'\n';
	}
	
}
int main(void)
{
	taofile();
	fp1>>n;
	canh1 b[100];
	int t=0;
	int x,y,z;
	while(true)
	{
		fp1>>x>>y>>z;
		if(fp1==NULL)
		{
			break;
		}
		else
		{
			b[t].t=x;
			b[t].s=y;
			b[t].tso=z;
			t++;
		}
	}
	fp1.close();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
	 a[i][j]=MAX;
	}
	
	for(int i=0;i<t;i++)
	{
		a[b[i].t][b[i].s]=b[i].tso;
		a[b[i].s][b[i].t]=b[i].tso;
	}
	cout<<'\n';
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		cout<<a[i][j]<<"         ";
		cout<<'\n';	}
		cout<<'\n';
	Floyd(1);
	
	return 0;
}
