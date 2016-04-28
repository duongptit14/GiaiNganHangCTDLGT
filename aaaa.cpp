#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream ifs("input.txt", ios::in);
	string s;
	int n;
	while(1) {
		ifs >> n;
		if(ifs.eof()) break;
		cout << n << " " ;
		
		
	}
	return 0;
}
