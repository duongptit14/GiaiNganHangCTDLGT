#include<iostream>
#include<string>
using namespace std;

char a[100];
int x[100];	// so luong cac ky tu
int sl=0;

void sort(){
	for(int i=1;i<sl;i++){
		for(int j=i+1;j<=sl;j++){
			if(x[i] < x[j]){
				int tmp = x[i];
				x[i] = x[j];
				x[j] = tmp;
				
				char tmp1 = a[i];
				a[i] = a[j];
				a[j] = tmp1;
			}
		}
	}
}

int main(){
	string s="GEEKSFORGEEKS";
	int l=s.length();
	int d=3;
	char KQ[100];
	for(int i=0;i<l;i++)	KQ[i]=' ';
	
	for(int i=0; i<l; i++){
		int j;
		for(j=1;j<=sl;j++){
			if( s[i] == a[j]){
				x[j]++;
				break;
			}
		}
		if(j>sl){
			sl++;
			a[sl]=s[i];
			x[sl]=1;
		}
	}
		
	sort();
	int i=1;
	while(i<=sl){
		int p=x[i];
		char z=a[i];
		int k;
		for( k=0; k<l;k++){
			if(KQ[k] == ' ') 	break;
			
		}
		if(k>l){
			cout<<"KHong co loi giai";
			return 0;
		}
		for(int t=0;t<p;t++){
			if(k+t*d > l){
				cout<<" khong co loi giai";
				return 0;
			}else{
				KQ[k+t*d] = z;
			}
		}
		i++;
	}
	for(int i=0;i<l;i++){
		cout<<KQ[i];
	}
		
	return 0;
}
