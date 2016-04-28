#include <iostream>
#include <fstream>

using namespace std;
#define MAX 100001
int A[MAX];
int NT[MAX];
int res;
ifstream ifs;
ofstream ofs;
void sang() {
	for( int i = 2; i<=MAX; i++) {
		if( NT[i]==0 ) {
			for( int j = 2; i*j <=MAX; i++ ) {
				NT[i*j] = 1;
			}
		} 
	}
}
bool isTN( int n) {
	int dao = 0;
	int tmp = n;
	while(n) {
		dao = dao*10 + n%10;
		n /= 10;
	}
	if(dao == tmp ) return true;
	return false;
}
int main() {
	sang();
	ifs.open("data.in", ios::in);
	int tmp;
	int count = 0;
	while(1) {
		ifs >> tmp;
		if(ifs.eof()) break;
		count++;
		if(NT[tmp]==0 && isTN(tmp)) {
			A[tmp]++;
			if( res < tmp) res = tmp;
		}	
	}
	ifs.close();
	cout << res << " " << (float)A[res]/count;
	return 0;
}
