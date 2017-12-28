#include<iostream>
using namespace std;

void merge(int a[], int l, int m, int r){

	int n1 = m - l + 1;
	int n2 = r - m;
	int L[100], R[100];
	for (int i = 0; i < n1; i++){
		L[i] = a[l + i];
	}
	for (int i = 0; i < n2; i++){
		R[i] = a[m + 1 + i];
	}

	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2){
		if (L[i] <= R[j]){
			a[k] = L[i];
			i++;
		}
		else{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1){
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < n2){
		a[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int a[], int l, int r){
	if (l < r){
		int m = (l + r - 1) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

void print_Arrays(int a[],int n){
	for(int i=0;i<n;i++) cout<<a[i]<<" ";	
}

int main(){
	int a[]={1,3,2,1,5,7,4,5};
	int n=sizeof(a)/sizeof(a[0]);
	mergeSort(a,0,n);
	print_Arrays(a,n);
	return 0;
}
