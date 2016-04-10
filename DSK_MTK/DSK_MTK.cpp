#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;
int a[100][100];

int main() {
	ifstream ifs("DSK.txt", ios::in);
	int n; 
	ifs >> n;
	char tmp[100];
	ifs.getline(tmp,1);
	int i = 1;
	while(!ifs.eof()) {
		ifs.getline(tmp,100);	
		char *p = strtok(tmp, " ");
		while(p!=NULL) {
			string tmp2 = (string)p;
			int num = atoi(tmp2.c_str());
			a[i][num]++;
			p = strtok(NULL, " ");
		}
		i++;
		cout << endl;
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
