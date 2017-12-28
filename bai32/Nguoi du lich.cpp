#include<iostream>
using namespace std;

int kq[7];
int x[7];
int MIN=1000;
int a[5][5]={
	{0,1,7,9,1},
	{1,0,6,2,6},
	{7,6,0,3,2},
	{9,2,3,0,4},
	{1,6,2,4,0}	};

int daxet[10]={0};

void Try(int i){
	for(int j = 2;j <= 5;j++){
		if(!daxet[j]){
			daxet[j]=1;
			x[i]=j;
			
			if(i == 4){
				int s = 0;
				s+=a[0][ x[1] ];
				for(int k = 2;k < 5;k++){
					s += a[ x[k-1] ][ x[k] ];
				}
				s+=a[ x[4] ][0];
			
				if(s<MIN){
					MIN=s;
					kq[1]=1;
					for(int i=2;i<=5;i++)	kq[i]=x[i-1];
					kq[6]=1;	
				}
			}else Try(i+1);
			daxet[j]=0;
		}	
	
	}
}

int main(){
//	for(int i=0;i<5;i++){
//		for(int j=0;j<5;j++)	cout<<a[i][j]<<" ";
//		cout<<"\n";
//	}
	Try(1);
	cout<<"Cost min: "<<MIN<<"\n";
	cout<<"Hanh trinh: ";
	for(int i=1;i<=6;i++){
		cout<<kq[i]<<" ";
	}
	return 0;
}
