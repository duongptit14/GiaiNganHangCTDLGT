#include<iostream>
#include<fstream>
using namespace std;
int n,k,a[100],X[100];
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
	}
	for(int i=1;i<=n;i++)
	X[i]=0;
}
int ktra2()
{
	int tong=0;
	for(int i=1;i<=n;i++)
	tong+=X[i]*a[i];
	return tong;
}
void in()
{
	for(int i=1;i<=n;i++)
	if(X[i]==1)
	{
		fp3<<X[i]*a[i]<<" ";
		cout<<X[i]*a[i]<<" ";
	}
	fp3<<'\n';
	cout<<'\n';
}
void Try(int i)
{
	for(int j=0;j<=1;j++)
	{
		X[i]=j;
		if(i==n)
		{
			if(ktra2()==k)
			{
				in();
			}
		}
		else Try(i+1);
	}
}
int dem=0;
void Try1(int i)
{
	for(int j=0;j<=1;j++)
	{
		X[i]=j;
		if(i==n)
		{
			if(ktra2()==k)
			{
				dem++;
			}
		}
		else Try1(i+1);
	}
}
int main(void)
{
	taofile();
	tao();
	Try1(1);
	cout<<dem<<'\n';
	Try(1);
	return 0;
}
