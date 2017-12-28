// bai toan Day con co tong = S
#include <iostream>
#include <fstream>

using namespace std;
int truoc[200];
int main() {
	//ifstream ifs("qhd.txt", ios::in);
	//if( !ifs.is_open()) {
	//	cout << "Chua co file !" << endl;
	//	return 0;
	//}
	int n; // n - so phan tu cua day
	int S; // S - tong
	int a[200]; // a - mang day so
	cin >> n >> S;
	for( int i = 1; i<=n; i++ ) cin >> a[i];
	int L[200];
	//
	// L[S] = 0;
	L[0] = 1;
	for( int i = 1; i<=n; i++ ) {
		for( int t = S; t >= a[i]; t-- ) {
			if( L[t] ==  0  && L[t-a[i]] == 1) {
				L[t] = 1;
				truoc[t] = t-a[i];
			}
		}
	}
	// hien thi ket qua
	int tg = S;
	while(tg) {
		cout << tg-truoc[tg] << " ";
		tg = truoc[tg];
	}
	return 0;
}
