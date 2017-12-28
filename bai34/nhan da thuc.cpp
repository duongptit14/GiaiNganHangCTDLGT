#include<iostream>
using namespace std;

int n=3;
int m=3;
int a[4]={1,3,0,2};
int b[4]={1,1,2,1};

int z=m+n;
int c[100];

void nhan(){
	int z;
	for(int i=0;i<=m+n;i++){
		c[i]=0;
	}
	for(int i=0;i<=m+n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=m;k++){
				if(j+k==i)	c[i]+=a[j]*b[k];	
			}
		}
	}
} 
void xuat(){
	for(int i=0;i<=m+n;i++){
		cout<<c[i]<<" ";
	}
}
int main(){
	nhan();
	xuat();
	return 0;
}
