#include<iostream>
using namespace std;

int partition(int a[], int l, int h){
	int x = a[h];
	int i = l - 1;
	for (int j = l; j <= h - 1; j++){
		if (a[j] <= x){
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[h]);
	return i + 1;
}

void quickSort(int a[], int l, int h){
	if (l < h){
		int p = partition(a, l, h);
		quickSort(a, l, p - 1);
		quickSort(a, p + 1, h);
	}
}

void print_Arrays(int a[],int n){
	for(int i=0;i<n;i++)	cout<<a[i]<<" ";
}

int main(){
	int a[]={1,3,2,5,10,20,4,1};
	int n=sizeof(a)/sizeof(a[0]);
	quickSort(a,0,n-1);
	print_Arrays(a,n);
	return 0;
}
