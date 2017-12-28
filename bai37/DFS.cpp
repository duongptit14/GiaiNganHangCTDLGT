// DFS - de quy
#include <iostream>
#include <fstream>
#define MAX 20
using namespace std;
ifstream ifs;
int n; // so dinh
int a[MAX][MAX]; // ma tran ke
int visit[MAX]; // mang danh dau 
void DFS(int u) {
	cout << u << " ";
	visit[u] = 1;
	for( int i = 1; i<=n; i++ ) {
		if( visit[i] == 0 && a[u][i]) {
			visit[i] == 1;
			DFS(i);
		}
	}
}
int main() {
	ifs.open("MTK.txt", ios::in);
	ifs >> n;
	for( int i = 1; i<=n; i++ ) {
		for( int j = 1; j<=n; j++ ) ifs >> a[i][j];
	}
	DFS(1);
	
	return 0;
}
