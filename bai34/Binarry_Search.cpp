#include<iostream>
using namespace std;

int binary_Search(int a[],int x,int f,int e){
	int mid=(f+e)/2;	
	while(f<=e){
		if(x>a[mid])	f=mid+1;
		else if(x<a[mid])	e=mid-1;
		else if(x == a[mid])	return mid;	
		mid=(f+e)/2;
	}
	return -1;
}
 

int main(){
	
	int a[]={1,2,4,6,7,12,20,30};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<binary_Search(a,4,0,n);
	return 0;
}
