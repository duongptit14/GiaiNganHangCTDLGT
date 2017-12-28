#include <iostream>
using namespace std;
int n, a[100], OK = 1;
void init() {
	cout << "Nhap n = "; cin >> n;
}
void result() {
	for( int i = 1; i<=n; i++) cout << a[i] << " ";
	cout << endl;
}
void sinh() {
	int k = n;
	while( k > 0 && a[k] == 1) {
		a[k] = 0; k--;
	} 
	if( k > 0 ) a[k] = 1;
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
