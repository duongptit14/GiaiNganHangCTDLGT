// bai toan Cai tui - QHD
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream ifs("qhd.txt", ios::in);
	if( !ifs.is_open()) {
		cout << "Chua co file !" << endl;
		return 0;
	}
	int n; // n - so luong do vat
	int W; // W - khoi luong toi da tui co the chua
	int a[200]; // a - mang luu trong luong cua tui
	int b[200]; // b - mang luu gia tri cua tui
	ifs >> n >> W;
	for( int i = 1; i<=n; i++ ) {
		ifs >> a[i] >> b[i];
	}
	//
	int L[200][200];
	for( int i = 1; i<=n; i++ ) {
		for( int j = 1; j<= W; j++ ) {
			if( b[i] < j ) {
				L[i][j] = max(L[i-1][j-a[i]] + b[i], L[i-1][j]);
			}
			else L[i][j] = L[i-1][j];
		}
	}
	//
	cout << L[n][W];

	return 0;
}