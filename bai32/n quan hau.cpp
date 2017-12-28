#include <iostream>

using namespace std;
int n, a[100], b[100], c[100];
int x[100]; // mang kq
void init() {
	cout << "Nhap n :"; cin >> n;
}
void result() {
	for( int i = 1; i<=n; i++) cout << x[i] << " ";
	cout << endl;
}
void Try( int i ) {
	for( int j = 1; j<=n; j++) {
		if( a[j] == 0 && b[i+j] == 0 && c[i-j] == 0) {
			x[i] = j;
			a[j] = 1; b[i+j] = 1; c[i-j] = 1;
			if( i == n ) result();
			else Try(i+1);
			a[j] = 0; b[i+j] = 0; c[i-j] = 0;
		}
	}
}
int main() {
	init();
	Try(1);
	return 0;
}
