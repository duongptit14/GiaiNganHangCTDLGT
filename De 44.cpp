#include<iostream>
#include<fstream>
using namespace std;
int n,k,a[100],X[100],b[100];
	fstream fp1;
	ofstream fp3;
void taofile()
{
	fp1.open("DATA1.in");
	fp3.open("ketqua.out");
}
void tao()
{
	fp1>>n>>k;
	for(int i=1;i<=n;i++)
	{
		fp1>>a[i];
		fp1>>b[i];
	}
	for(int i=1;i<=n;i++)
	X[i]=0;
}
void tiep()
{
	int i=n;
	while(X[i]==1)
	{
		X[i]=0;
		i--;
	}
	X[i]=1;
}
int ktra()
{
	for(int i=1;i<=n;i++)
	if(X[i]==0) return 0;
	return 1;
}
int ktra2()
{
	int tong=0;
	for(int i=1;i<=n;i++)
	tong+=X[i]*a[i];
	return tong;
}
int ktra3()
{
	int dem=0;
	for(int i=1;i<=n;i++)
	dem+=X[i]*b[i];
	if(dem>k) return 0;
	return 1;
}
/*void in()
{
	for(int i=1;i<=n;i++)
	{
		fp3<<X[i]*a[i]<<" ";
		cout<<X[i]*a[i]<<" ";
	}
	fp3<<'\n';
	cout<<'\n';
}*/
int main(void)
{
	int m=0;
	int c[100]={0};
	taofile();
	tao();
	while(!ktra())
	{
		if(ktra3())
		{
			if(ktra2()>m)
			{
				m=ktra2();
				for(int i=1;i<=n;i++)
				c[i]=X[i];
			}
			
		}
		tiep();
	}
	if(ktra3())
		{		m=ktra2();
				for(int i=1;i<=n;i++)
				c[i]=X[i];
		}
	cout<<m<<'\n';
	fp3<<m<<'\n';
	for(int i=1;i<=n;i++)
	{
		cout<<c[i]<<" ";
		fp3<<c[i]<<" ";
	}
	return 0;
}
