#include <iostream>

using namespace std;
int n, x[100], daxet[100];
void init() {
	cout << "Nhap n :"; cin >> n;
}
void result() {
	for( int i = 1; i<=n; i++) cout << x[i] << " ";
	cout << endl;
}
void Try( int i ) {
	for( int j = 1; j<=n; j++) {
		if( daxet[j] == 0) {
			x[i] = j; daxet[j] = 1;
			if( i == n) result();
			else Try(i+1);
			daxet[j] = 0;
		}
	}
}
int main() {
	init();
	Try(1);	
	return 0;
}
