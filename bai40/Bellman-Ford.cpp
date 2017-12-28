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
void Bellman_Ford(int u)
{
	int d[10],Trace[10];
	for(int i=1;i<=n;i++)
	{
		d[i]=a[u][i];
		Trace[i]=u;
	}
	bool stop=false;
	int countloop=0;
	while(stop==false&&countloop<n-2)
	{
		stop=true;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(d[j]>d[i]+a[i][j])
				{
					d[j]=d[i]+a[i][j];
					Trace[j]=i;
					stop=false;
				}
			}
		}
		countloop++;
	}
	
	for(int j=1;j<=n;j++)
	{
		cout<<"khoang cach tu  "<<u<<" toi "<<j<<" "<<d[j]<<'\n';
		int temp=j;
		while(temp!=u)
		{
			cout<<temp<<"<-";
			temp=Trace[temp];	
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
	Bellman_Ford(1);
	
	return 0;
}
