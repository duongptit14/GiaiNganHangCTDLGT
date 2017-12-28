#include<iostream>
using namespace std;
int b[6]={6,4,5,2,9,7};		// khoi luong
int a[6]={4,2,5,7,3,1};		// gia tri
int n=6, m= 16, kl;
int MAX=0;
int kq[100];
int x[100];


int tmp_gtri=0, tmp_kl=0;

void Try(int i) {
	for( int k = 0; k<=1; k++) {
		x[i] = k;
		if( i == n){
			for(int j=1;j<=n;j++){
				if(x[j] == 1){
					tmp_gtri += a[j-1];
					tmp_kl += b[j-1];
				}
			}
			
			if( tmp_gtri > MAX && tmp_kl <= m){	
				MAX=tmp_gtri;
				kl=tmp_kl;	
				for(int i=1;i<=n;i++)	kq[i]=x[i];						
			}
			
			tmp_gtri = 0;
			tmp_kl = 0;		
		
		}
		else Try(i+1);
	}
}

void print(){
	cout<<"Gia tri max: "<<MAX<<"\n";
	cout<<"KL: "<<kl<<"\n";
	for(int i=1;i<=n;i++){
		if(kq[i]==1)	cout<<a[i-1]<<"\t"<<b[i-1]<<"\n";
	}
}

int main(){
	Try(1);
	print();
}
