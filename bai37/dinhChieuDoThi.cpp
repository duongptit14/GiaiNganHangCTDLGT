#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;
int n, m, A[MAX][MAX];
int seen[MAX];
int Low[MAX];
int Numbering[MAX];
int count = 0;
void init() {
	cin >> n >> m;
	for( int i = 1; i<=m; i++ ) {
		int u, v; cin >> u >> v;
		A[u][v] = 1; A[v][u] = 1;
	}
//	memset(Low,10000,sizeof(Low));
}
void Visit(int u) {
	seen[u] = 1;
	Numbering[u] = count++;
	Low[u] = 10000;
	for( int v = 1; v <=n; v++ ) {
		if(A[u][v]) {
			A[v][u] = 0;
			if(seen[v] == 0 ) {
				Visit(v);
				if(Low[v] > Numbering[u]) cout << "Canh cau : " << u << " " << v << endl;
				Low[u] = min(Low[u], Low[v]); // cuc tieu hoa
			}
			else Low[u] = min(Low[u], Numbering[v]); // cuc tieu hoa
		}
	}
}
void process() {
	init();
	for( int i = 1; i<=n; i++ ) {
		if(seen[i]==0) Visit(i);
	}
}
int main() {
	process();
	
	return 0;
}
