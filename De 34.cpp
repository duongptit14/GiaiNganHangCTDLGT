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
	int kt=0,kt1=0;
	for(int i=1;i<=n;i++)
	{
		if(X[i]==1)
		{
			kt=X[i]*a[i];
			break;
		}
	}
	for(int i=1;i<=n;i++)
	if(X[i]==1)
	{
		if(X[i]*a[i]<kt)
		{
			kt1=1;
			break;
		}
		kt=X[i]*a[i];
	}
	if(kt1==1) return 0;
	return 1;
}
int ktra3()
{
	int dem=0;
	for(int i=1;i<=n;i++)
	if(X[i]==1) dem++;
	if(dem==3) return 1;
	return 0;
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
int main(void)
{
	int dem=0;
	taofile();
	tao();
	while(!ktra())
	{
		if(ktra3())
		{
			if(ktra2())
			dem++;
		}
		tiep();
	}
	if(ktra3())
		{
			if(ktra2())
			dem++;
		}
	fp3<<dem<<'\n';
	cout<<dem<<'\n';
	tao();
	while(!ktra())
	{
		if(ktra3())
		{
			if(ktra2())
			in();
		}
		tiep();
	}
	if(ktra3())
		{
			if(ktra2())
			in();
		}
	return 0;
}
