#include <iostream>

using namespace std;
int n, a[100][100];
int p[] = {-2,-2,2,2,-1,-1,1,1};
int q[] = {1,-1,1,-1,2,-2,2,-2};
int x, y;
void init() {
	cout << "Nhap kich thuoc ban co :"; cin >> n;
	cout << "Nhap toa do vi tri dau tien :"; cin >> x >> y;
}
void result() {
	for( int i = 1; i<=n; i++) {
		for( int j = 1; j<=n; j++) cout << a[i][j] << " ";
		cout << endl;
	}
	cout << "___________________" << endl;
}
void Try( int x, int y, int k) {
	if( k >= n*n ) result();
	else for( int i = 1; i<=8; i++ ) {
		int x1 = x + p[i];
		int y1 = y + q[i];
		if( 1<=x1 && x1 <=n && 1 <= y1 && y1 <=n && a[x1][y1] == 0) {
			a[x1][y1] = k;
			Try(x1,y1,k+1);
			a[x1][y1] = 0;
		}
	}
}
int main() {
	init();
	a[x][y] = 1;
	Try(x,y,2);
	
	return 0;
}
