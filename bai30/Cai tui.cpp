#include<iostream>
using namespace std;

int b[6]={6,4,5,2,9,7};		// khoi luong
int a[6]={4,2,5,7,3,1};		// gia tri
int n=6, m= 16, OK=1;
int sl, MAX=0,  kl=m;
int kq[7];
int x[7];
void sinh(){	
	int i = n;
	while( i>0 && x[i] == 1) {
		x[i] = 0; i--;
	} 
	if(i > 0){
		x[i] = 1;
		int s1 = 0,s2 = 0;
		for(int j=1;j<=n;j++){
			if(x[j]==1){
				s1+=a[j-1];
				s2+=b[j-1];
			}
		}
		if( s1>MAX && s2<=m){		
			for(int i=1;i<=n;i++)	kq[i]=x[i];
			MAX=s1;
			kl=s2;
		}
	}else{
		OK=0;
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
	while(OK){
		sinh();
	}
	print();
	return 0;
}
