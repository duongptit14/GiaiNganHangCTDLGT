#include <iostream>

using namespace std;
int n, k, OK = 1, a[100];
void init() {
	cout << "Nhap n va k :"; cin >> n >> k;
	for( int i = 1; i<=k; i++) a[i] = i;
}
void result() {
	for( int i = 1; i<=k; i++) cout << a[i] << " ";
	cout << endl;
}
void sinh() {
	int i = k;
	while( i>0 && a[i] == n-k+i) i--;
	if( i>0 ) {
		a[i]++;
		for( int j = i+1; j<=k; j++ ) a[j] = a[j-1]+1;
	}
	else OK = 0;
}
void process() {
	init();
	while(OK) {
		result();
		sinh();
	}
}
int main() {
	process();
	return 0;
}
