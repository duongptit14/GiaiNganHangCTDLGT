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
struct canh{	
	int trc;
	int sau;
};
//tao tap cay khung T
struct canh1{
	int t;
	int s;
	int tso;
};
//tao input
int n;
void Kruskal(canh1 b[100],int dem)
{
	canh T[100];
	
	int h=0,u=0;
	int dh=0,a[100];
	for(int i=1;i<=n;i++)
	a[i]=0;
	while(h<n-1&&u<dem)
	{
		
			a[b[u].t]=1;
			a[b[u].s]=1;
			T[h].trc=b[u].t;
			T[h].sau=b[u].s;
			dh+=b[u].tso;
			h++;		
		
		u++;
	}
	cout<<dh<<'\n';
	fp2<<dh<<'\n';
	for(int i=0;i<h;i++)
	{
		cout<<T[i].trc<<" "<<T[i].sau<<'\n';
		fp2<<T[i].trc<<" "<<T[i].sau<<'\n';
	}
}
int main(void)
{
	taofile();
	fp1>>n;
	canh1 b[100];
	int t=0;
	int x,y,z,dem=0;
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
		dem++;
	}
	for(int i=0;i<t-1;i++)
	{
		for(int j=i+1;j<t;j++)
		if(b[i].tso>b[j].tso)
		{
			canh1 temp=b[i];
			b[i]=b[j];
			b[j]=temp;
		}
	}
	for(int i=0;i<t;i++)
	cout<<b[i].t<<" "<<b[i].s<<" "<<b[i].tso<<'\n';
	fp1.close();
	Kruskal(b,dem);
	return 0;
}
