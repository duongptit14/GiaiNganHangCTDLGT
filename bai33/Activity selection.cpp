#include<iostream>
using namespace std;

int n=8;
int s[]={1,3,0,5,8,5,9,14};
int f[]={2,4,6,7,9,9,12,18};
int opt[100];
int sl=1;
void swap(int &a,int &b){
	int tmp=a;
	a=b;
	b=tmp;
}

void sort(){
	for(int i=0;i<7;i++){
		for(int j=i+1;j<8;j++){
			if(f[i] > f[j]){
				swap(s[i],s[j]);
				swap(f[i],f[j]);
			}
		}
	}
}

void Activity_Selection(){
	sort();
	opt[sl] = 0;
	for(int j=1;j<8;j++){
		if(s[j] >= f[ opt[sl] ]){
			sl++;
			opt[sl] = j;
		}
	}
}

void print(){
	for(int i=1;i<=sl;i++){
		cout<<s[ opt[i] ]<<"\t"<<f[ opt[i] ]<<"\n";
	}
}

int main(){
	Activity_Selection();
	print();
	return 0;
}
