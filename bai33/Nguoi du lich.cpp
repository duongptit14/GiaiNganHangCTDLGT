#include<iostream>
using namespace std;
	
int a[100][100]={
	{0,1,2,7,5},
	{1,0,4,4,3},
	{2,4,0,1,2},
	{7,4,1,0,2},
	{5,3,2,3,0}
};
int n=5;
int daxet[100]={0};
int kq[100];
int cost=0;
void action(){
	kq[0]=1;
	int vt=0;
	int sl=0;
	while(1){
		int i=vt;
		daxet[i]=1;
		int min=1000;
		for(int j=0;j<n;j++){
			if(!daxet[j] && a[i][j] < min ){
				min=a[i][j];
				vt=j;
			}
		}
		cost+=a[i][vt];
		sl++;
		kq[sl]=vt+1;
		daxet[vt]=1;
		
		for(i=0;i<n;i++){
			if(!daxet[i]) break;
		}
		if(i==n){
			cost += a[vt][0];
			return;
		}
	}
}

void print(){
	cout<<"Cost min: "<<cost<<"\n";
	cout<<"hanh trinh: \n";
	for(int i=0;i<n;i++){
		cout<<kq[i]<<" ";
	}
	cout<<1;
}
int main(){
	action();
	print();
	return 0;
}

