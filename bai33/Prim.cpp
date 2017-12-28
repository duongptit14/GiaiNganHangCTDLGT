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
int a[10][10],n;
void Prim(int u)
{
	int Vh[100],V[100],d=0,tong=0;//Vh tap ban dau,V tap bot di u,d do dai cay khung min
	canh T[100];int g=0;
	Vh[1]=u;V[1]=0;
	for(int i=2;i<=n;i++)
	{
		V[i]=i;
		tong+=i;
	}
	//khoi tao
	int e=1,f=n;
	while(tong>0)
	{
		int min=MAX,temp,temp1;
		for(int i=1;i<=e;i++)
		{
			for(int j=2;j<=f;j++)
			{
				if(V[j]>0)
				{
				if(a[Vh[i]][V[j]]<min)
				{
					min=a[Vh[i]][V[j]];
					temp=i;
					temp1=j;
				}
				}
				
			}
		}
		//tim canh co do dai min ma i thuoc vh, j thuoc v
		d=d+min;
		T[g].trc=temp;
		T[g].sau=temp1;
		g++;
		V[temp1]=-1;// loai bo temp1 o V
		e++;
		Vh[e]=temp1;// the temp1 vao vh
		tong=tong-temp1;	
	}
	cout<<d<<'\n';
	fp2<<d<<'\n';
	for(int i=0;i<g;i++)
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
	a[i][j]=MAX;
	
	for(int i=0;i<t;i++)
	{
		a[b[i].t][b[i].s]=b[i].tso;
		a[b[i].s][b[i].t]=b[i].tso;
	}
	cout<<'\n';
	Prim(1);
	return 0;
}
