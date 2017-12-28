// xau con chung dai nhat
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
	ifstream ifs("qhd.txt", ios::in);
	if( !ifs.is_open()) {
		cout << "Chua co File !" << endl;
		return 0;
	}
	string X, Y;
	ifs >> X >> Y;
	//
	int L[200][200];

	/* Ham quy hoach dong
		L[0,j]=L[i,0]=0.
		L[i,j] = L[i−1,j−1]+1 nếu Xi = Yj.
		L[i,j] = max( L(i−1,j), L[i,j−1] ) nếu Xi≠Yj.
	*/
	int m = X.length();
	int n = Y.length();
	for( int i = 0; i<=m; i++) L[i][0] = 0;
	for( int j = 0; j<= n; j++) L[0][j] = 0;
	for( int i = 1; i<=m; i++ ) {
    	for( int j = 1; j<=n; j++) {
           if (X[i] == Y[j] ) L[i][j] = L[i–1][j–1]+1;
           else L[i][j] = max(L[i–1][j] , L[i][j–1]]);	
   		}
    }
	return 0;
}