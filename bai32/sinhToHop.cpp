#include <iostream>

using namespace std;
int n, k, x[100];
void init() {
	cout << "Nhap n va k :"; cin >> n >> k;
}
void result() {
	for( int i = 1; i<=k; i++) cout << x[i] << " ";
	cout << endl;
}
void Try(int i) {
	for( int j = x[i-1] +1; j<= n-k+i; j++) {
		x[i] = j;
		if( i == k) result();
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
