#include <iostream>
#include <fstream>
#define MAX 100
using namespace std;
ifstream ifs;
ofstream ofs;

int main() {
	ifs.open("DSC.txt", ios::in);
	int n; // so dinh
	int m; // so canh
	int a[MAX][MAX];
	ifs >> n >> m;
	int u, v;
	for( int i = 1; i<=m; i++ ) {
		ifs >> u >> v;
		a[u][v] = 1;
		a[v][u] = 1;
	} 
	ofs.open("MTK.txt", ios::out);
	ofs << n << endl;
	for( int i = 1; i<=n; i++ ) {
		for( int j = 1; j<=n; j++ ) {
			ofs << a[i][j] << " "; 
		}
		ofs << endl;
	}
	ofs.close();
	ofs.open("DSK.txt", ios::out);
	ofs << n << endl;
	for( int i = 1; i<=n; i++ ) {
		for( int j = 1; j<=n; j++ ) {
			if( a[i][j]) ofs << j << " ";
		}
		ofs << endl;
	}
	ofs.close();

	return 0;
}