// bai toan cho thue may
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int n; // so may
	int a[200], b[200]; // a - mang time start , b - mang time end
	int c[200]; // c - mang chi phi
	ifstream ifs("qhd.txt", ios::in);
	if( !ifs.is_open()) {
		cout << "Cua co file ! " << endl;
		return 0;
	}
	ifs >> n;
	for( int i = 1; i<=n; i++ ) {
		ifs >> a[i] >> b[i] >> c[i];
	}
	// sap xep don hang theo thoi gian ket thuc
	for( int i = 1; i<n; i++ ) {
		for( int j = i+1; j<=n; j++ ) {
			if( b[i] > b[j] ) {
				swap(b[i], b[j]);
				swap(a[i], a[j]);
				swap(c[i], c[j]);
			}
		}
	} // end Sort
	int L[200]; // L - mang luu so tien lon nhat thu dc, L[i] => so tien lon nhat thu duoc tu may 0 -> i
	for(int i = 1; i<=n; i++ ) {
		L[i] = c[i]; 
		for( int j = 1; j<i; j++ ) {
			if( b[j] <= a[i] && L[i] < L[j] + c[i] ) {
				L[i] = L[j] + c[i];
			}
		}
	}
	// tim max trong L => res
	int res = 0; // ket qua
	for( int i = 1; i<=n; i++ ) {
		if( res < L[i] ) {
			res = L[i];
		}
	}
	cout << res << endl;




	return 0;
}