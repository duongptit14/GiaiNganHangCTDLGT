// tinh so thanh phan lien cua do thi
#include <iostream>
#include <fstream>
#include <queue>
#define MAX 20

using namespace std;

ifstream ifs;
int n;
int a[MAX][MAX];
int b[MAX][MAX]; // mang temple , b = a;
int visit[MAX];
int X; // so thanh phan lien thong ban dau cua do thi
void BFS(int u) {
	queue <int> q;
	q.push(u);
	visit[u] = 1;
//	cout << u << " ";
	while(!q.empty()) {
		int tmp = q.front();
		q.pop();
		for( int i = 1; i<=n; i++ ) {
			if( visit[i] == 0 && a[tmp][i]) {
				q.push(i);
				visit[i] = 1;
//				cout << i << " ";
			}
		}
	}
}
int soThanhPhanLienThong() {
	int count = 0;
	for( int i = 1; i<=n; i++ ) {
		if( visit[i] == 0 ) {
			BFS(i);
			count++;
		}
	}
	// reset visit
	for( int i = 1; i<=n; i++) {
		visit[i] = 0;
	}
	return count;
}
void lietKeCanhCau() { // voi do thi vo huong thi count = count / 2
	cout << "Cac canh cau :" ;
	int count = 0;
	for( int i = 1; i<=n; i++) {
		for( int j = 1; j<=n; j++ ) {
			if( a[i][j] == 1 ) { // co canh
				a[i][j] = 0; a[j][i] = 0;
				if( soThanhPhanLienThong() > X ) {
					cout << "("<< i <<"," << j << ") ";
					count++;
				}
				a[i][j] = b[i][j]; a[j][i] = b[j][i];
			}
		}
	}
//	cout << "Co " << count << " canh cau" << endl;
}
void lietKeDinhTru() {
	cout << "Cac dinh tru :";
	int count = 0;
	for( int i = 1; i<=n; i++ ) {
		for( int j = 1; j<=n; j++ ) { // loai bo cac canh quanh dinh i
			a[i][j] = 0;
			a[j][i] = 0;
		}
//		cout << "Dinh " << i << " " << soThanhPhanLienThong() << endl;
		if(soThanhPhanLienThong() >X +1) {
			cout << i << " ";
			count++;
		}
		// reset mang a
		for( int j = 1; j<=n; j++ ) {
			a[i][j] = b[i][j];
			a[j][i] = b[j][i];
		}
	}
	cout << endl;
}

int main() {
	ifs.open("MTK.txt", ios::in);
	ifs >> n;
	for( int i = 1; i<=n; i++ ) {
		for( int j = 1; j<=n; j++ ) {
			ifs >> a[i][j];
			b[i][j] = a[i][j];
		}
	}
	X = soThanhPhanLienThong();
	cout << "So thanh phan lien thong cua do thi : " << X << endl;
	lietKeCanhCau();
	lietKeDinhTru();
	return 0;
}
