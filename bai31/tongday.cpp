#include <iostream>
#define MAX 100
using namespace std;
int tong( int a[], int n ) {
	if( n == 1 ) return a[1];
	else return a[n] + tong(a,n-1);
}
int main() {
	int a[MAX];
	int n;
	cin >> n;
	for( int i = 1; i<=n; i++ ) cin >> a[i];
	cout << tong(a,n);


	return 0;
}