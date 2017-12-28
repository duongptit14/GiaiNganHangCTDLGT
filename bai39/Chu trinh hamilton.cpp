// chu trinh Hamilton
#include <iostream>
#include <fstream>
#define MAX 20

using namespace std;

ifstream ifs;
int n;
int a[MAX][MAX];
int visit[MAX];
int X[MAX]; // mang luu chu trinh Hamilton
void result() {
	for( int i = 1; i<=n; i++ ) {
		cout << X[i] << " ";
	}
	cout << "1" << endl;
}
void Hamilton(int i) {
	for( int j = 1; j<=n; j++ ) {
		if( visit[j] == 0 && a[X[i-1]][j]) {
			X[i] = j;
			if( i == n && a[X[i]][1]) result();
			else {
				visit[j] = 1;
				Hamilton(i+1);
				visit[j] = 0;
			}
		}
	}	
}
int main() {
	ifs.open("MTK.txt", ios::in);
	ifs >> n;
	for( int i = 1; i<=n; i++ ) {
		for( int j = 1; j<=n; j++ ) ifs >> a[i][j];
	}
	X[1] = 1;
	visit[1] = 1;
	Hamilton(2);
	result();
	return 0;
}
