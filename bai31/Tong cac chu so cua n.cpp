#include<iostream>
using namespace std;
int s=0;
int tong(int n)
{
	if(n==0) return s;
	else
	{
		s=s+n%10;
		return tong(n/10);}
}
int main()
{
	int n;
	cin>>n;
	cout<<tong(n);
	return 0;
}
