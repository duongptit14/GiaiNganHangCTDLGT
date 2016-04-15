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
int main(void)
{
	int dem=0;
	taofile();
	tao();
	while(!ktra())
	{
		if(ktra2()==k)
		{
			dem++;
		}
		tiep();
	}
	if(ktra2()==k) dem++;
	fp3<<dem<<'\n';
	cout<<dem<<'\n';
	tao();
	while(!ktra())
	{
		if(ktra2()==k)
		{
			in();
		}
		tiep();
	}
	if(ktra2()==k) in();
	return 0;
}
