// kiem tra tinh lien thong manh cua Do Thi bang DFS
#include <iostream>
#include <fstream>
#define MAX 10
using namespace std;

int n; // so dinh
int a[MAX][MAX]; // ma tran ke
int visit[MAX]; // mang danh dau
int Trace[MAX]; // mang luu vet duong di

ifstream ifs;

void docFile() {
	ifs.open("MTK.txt", ios::in);
	ifs >> n;
	for( int i = 1; i<=n; i++ ) {
		for( int j = 1; j<=n; j++ ) ifs >> a[i][j];
	}
}
void DFS( int u ) {
	visit[u] = 1;
	for( int i = 1; i<=n; i++ ) {
		if( visit[i] == 0 && a[u][i] ) {
			Trace[i] = u;
			DFS(i);
		}
	}
}
bool LT( int u ) {
	// reset visit
	for( int i = 1; i<=n; i++ ) visit[i] = 0;
	//
	DFS(u);
	for( int i = 1; i<=n; i++ ) {
		if( visit[i] == 0 ) return false;
	}
	return true;
}
bool isLienThongManh() {
	for( int i = 1; i<=n; i++ ) {
		if( !LT(i) ) return false;
	}
	return true;
}
void DuongDi() {
	int s, f; // s- dinh xuat phat , f - dinh ket thuc
	cout << "Nhap vao dinh dau va dinh cuoi :"; cin >> s >> f;
	DFS(s);
	while( f != s ) {
		cout << f << "<-" ;
		f = Trace[f];
	}
	cout << f << endl;
} 
int main() {
	docFile();

	return 0;
}