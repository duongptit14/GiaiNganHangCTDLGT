// so nghiem nguyen khong am cua PT X1 + X2 + ... + Xn = k 
// bai co ban TRR1
#include <iostream>

using namespace std;
int C( int n, int k) {
	if( k == 0 || k == n) return 1;
	return C(n-1,k-1) + C(n-1,k);
}
int main() {
	int n, k;
	cin >> n >> k;
	cout << "So nghiem nguyen khong am :" << C(n-1+k, k);
	return 0;
}