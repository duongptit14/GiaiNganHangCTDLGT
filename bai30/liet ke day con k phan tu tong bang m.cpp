#include<iostream>
using namespace std;
int a[5]={5,2,3,4,1};
int n=5, k=2,m=5;

int main(){
	for(int i=0;i<=n-k;i++){
		int s=a[i];
		if(s==m && k==1){
			cout<<a[i]<<"\n";
		}else{
			int j;
			for(j=i+1;j<i+k;j++){
				s+=a[j];
			}
			if(s==m){
				for(int t=i;t<=j-1;t++){
					cout<<a[t]<<" ";
				}
				cout<<"\n";
			}
		}
	}
	return 0;
}
