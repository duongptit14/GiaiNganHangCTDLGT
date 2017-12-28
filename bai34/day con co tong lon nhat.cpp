#include<iostream>
using namespace std;
int maxadd(int a[],int n)
{
	int max1 = 0, max2 = 0;
	for(int i=0;i<n;i++)
	{
		max2 = max2+a[i];
		if(max2 < 0) max2 = 0;
		if(max1 < max2) max1 = max2;
	}
	return max1;
}
int main(void)
{
	int n,a[6]={1,4,-2,4,2,5};
	n=6;
	cout<<maxadd(a,n);
	return 0;
}
