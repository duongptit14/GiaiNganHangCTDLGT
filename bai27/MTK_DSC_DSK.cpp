#include <iostream>
#include <fstream>
#define MAX 100
using namespace std;
ifstream ifs;
ofstream ofs;
int main() {
	ifs.open("MTK.txt", ios::in);
	ofs.open("DSC.txt", ios::out);
	int n; // so dinh
	int a[MAX][MAX];
	ifs >> n;
	for( int i = 1; i<=n; i++ ) {
		for( int j = 1; j<=n; j++ ) {
			ifs >> a[i][j];
		}
	}
	ifs.close();
	int count = 0;
	ofs << n << " " << endl << endl << endl;
	for( int i = 1; i<=n; i++ ) {
		for( int j = i+1; j<=n; j++ ) {
			if( a[i][j] ) {
				ofs << i << " " << j << endl;
				count++;
			} 
		}
	}
	ofs.seekp(2);
	ofs << count;
	ofs.close();
	ofs.open("DSK.txt", ios::out);
	ofs << n << endl;
	for( int i = 1; i<=n; i++ ) {
		for( int j = 1; j<=n; j++ ) {
			if( a[i][j] ) {
				ofs << j << " ";
			}
		}
		ofs << endl;
	}
	ofs.close();
	return 0;
}