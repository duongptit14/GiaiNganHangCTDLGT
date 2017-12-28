#include <iostream>

using namespace std;
int a[100], n;
void init() {
	cout << "Nhap n = "; cin >> n;
}
void result() {
	for( int i = 1; i<=n; i++) cout << a[i] << " ";
	cout << endl;
}
void Try(int i) {
	for( int j = 0; j<=1; j++) {
		a[i] = j;
		if( i == n) result();
		else Try(i+1);
	}
}
void process() {
	init();
	Try(1);
}
int main() {
	process();
	return 0;
}
