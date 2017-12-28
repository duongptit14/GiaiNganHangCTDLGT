#include <iostream>
using namespace std;

int n=4;
int L[4]={4,3,2,6};
int cost=0;
void sort(){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(L[i] > L[j]){
				int tmp = L[i];
				L[i] = L[j];
				L[j] = tmp;
			}
		}
	}
}

void xoa(){
	int tmp = L[0] + L[1];
	for(int i = 1 ; i<n-1 ;i++){
		L[i] = L[i+1];
	}
	L[0]=tmp;
	n--;
}


void n_ropes(){
	while(n>1){
		sort();
		xoa();
		cost += L[0];
	}
}

int main(){
	n_ropes();
	cout<<"Cost min: "<<cost;
	return 0;
}
