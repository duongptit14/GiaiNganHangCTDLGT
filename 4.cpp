#include <iostream>
#include <fstream>
#define MAX 10001
using namespace std;
ifstream ifs;
ofstream ofs;

typedef struct {
	string s;
	int num;
} Item;

class List {
	public:
		Item list[MAX];
		int top;
		void add_begin(string s) {
			Item tmp;
			tmp.s = s;
			tmp.num = 1;
			top++;
			list[top] = tmp;
		}
		void show() {
			for( int i = 0; i<=top; i++) {
				cout << list[i].s << " " << list[i].num << endl;
			}
		}
		void search(string s) {
			if(top==-1) {
				add_begin(s); return;
			}
			int i ;
			for(i = 0; i<=top; i++) {
				if( list[i].s == s ) {
					list[i].num++;
					break;
				}
			}
			if(i==top+1) {
				add_begin(s);
			}
		}
		List() {
			top = -1;
		}		
		
};
int main() {
	List list;
	ifs.open("data1.txt", ios::in);
	string s;
	int dem = 0;
	while(1) {
		ifs >> s;
		if(ifs.eof()) break;
		list.search(s);
		dem++;
	}
	ifs.close();
	ifs.open("data2.txt", ios::in);
	while(1) {
		ifs >> s;
		if(ifs.eof()) break;
		list.search(s);
		dem++;
	}
	ofs.open("ketqua.txt", ios::out);
	while(list.top >= 0) {
		ofs << list.list[list.top].s << " " << (float)list.list[list.top].num/dem << endl;
		list.top--;
	} 
//	list.show();
	
	return 0;
}
