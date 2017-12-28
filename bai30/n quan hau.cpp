#include<iostream>
using namespace std;
int n=4;
int c[10] = {0};

int xuoi[20] = {0};
int nguoc[20] = {0};
int a[10];
int OK = 1;

void print(){
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

void sinh(){	// sinh hoan vi
	int i=n-1;
    while(i>0 && a[i]>a[i+1]) i--;
        if(i>0){   
			int j=n;
            while(j>0 && a[i]>a[j])   j--;
            int tmp=a[i];
			a[i]=a[j];	a[j]=tmp;	
            int r=i+1, s=n;
            while(r<=s){
                int tmp=a[r];	a[r]=a[s];	a[s]=tmp;
                r++;	s--;
            }
//			for(int i=1;i<=2*n;i++){
//				cout<<c[i]<<"\t"<<xuoi[i]<<"\t"<<nguoc[i]<<"\n";
//			}			
			for(j=1;j<=n;j++){
				if(c[ a[j] ] ==1 || xuoi[ j - a[j] +n] == 1 || nguoc[j + a[j] -1]==1)	break;
				else{
					c[ a[j] ] = 1;
					xuoi[ j - a[j] +n] = 1;
					nguoc[j + a[j] -1]=1;
				}
			} 
			if(j>n){
				print();
			}
			for(j=1;j<=n;j++){
				c[j]=0;
				xuoi[j]=0;
				nguoc[j]=0;
			}
			for(j=n+1;j<=2*n-1;j++){
				xuoi[j]=0;
				nguoc[j]=0;
			}			              
        }
        else    OK=0;
}

int main(){
	for(int i=1;i<=n;i++)	a[i]=i;
	while(OK){
		sinh();
	}
	return 0;
}
