#include<iostream>
using namespace std;
int a[5]={5,2,3,4,1};
int n=5;
int k=5;
int main(){
	for(int i=0;i<n;i++){
		int s=a[i];
		if(s==k){
			cout<<s;
			cout<<"\n";
		}else{
			for(int j=i+1;j<n;j++){
				s+=a[j];
				if(s==k){
					for(int t=i;t<=j;t++)	cout<<a[t]<<" ";
					cout<<"\n";
					break;
				}
			}
		}
	
	}
	return 0;
}
