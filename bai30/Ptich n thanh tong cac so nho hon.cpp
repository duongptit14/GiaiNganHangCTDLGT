#include<iostream>
using namespace std;
int ok=true;
void Sinh(int *a,int n,int &vt){
	int i=vt,j;
	while(i>0&&a[i]==1)	i--;
	if(i>0){
		a[i]--;
		for(j=i+1;j<=n;j++){
			if(a[j]+1<=a[j-1]){
				a[j]++;
				if(j>vt)	vt=j;
				break;
			}
		}
	}
	else ok=false;
}
void Result(int *a,int vt){
	for(int i=1;i<=vt;i++)	cout<<a[i]<<" ";
	cout<<endl;
}
int main(){
	int n;
	cout<<"Nhap n: ";	cin>>n;
	int *a=new int [n+1];
	int vt=1;	a[vt]=n;
	for(int i=2;i<=n;i++)	a[i]=0;
	while(ok){
		Result(a,vt);
		Sinh(a,n,vt);
	}
	return 0;
}
