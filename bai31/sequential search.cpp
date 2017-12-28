#include<iostream>
using namespace std;
int tim(int a[],int n,int x)
{
	if(a[n]==x&&n>=0) return n;
	else if(n<0) return -1;
	else
	{
		return tim(a,n-1,x);
	}
}
int main()
{
	int n,x,a[100];
	cin>>n>>x;
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<tim(a,n,x);
	return 0;
}
