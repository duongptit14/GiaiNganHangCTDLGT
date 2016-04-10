#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
int a[100][100];
bool Find(string tmp, char c) {
	for( int i = 0; i<=tmp.length(); i++) {
		if( tmp[i] == c ) return true;
	}
	return false;
}
int main() {
	ifstream ifs("DSK.txt", ios::in);
	int n; 
	ifs >> n;
	string tmp;
	getline(ifs,tmp);
	int i = 1;
	while(!ifs.eof()) {
		getline(ifs,tmp);
		for( int j = 1; j<=n; j++) {
			char c = (j+48);
			if( Find(tmp,c) == true ) a[i][j] = 1;
		}
		i++;
	}
	ifs.close();
	ofstream ofs("MTK.txt");
	ofs << n << endl;
	for( int i = 1; i<=n; i++) {
		for( int j = 1; j<=n; j++) ofs << a[i][j] << " ";
		ofs << endl;
	}
	ofs.close();
	
	return 0;
}
