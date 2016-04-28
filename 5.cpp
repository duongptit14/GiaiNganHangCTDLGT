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
	List list1;
	List list2;
	
	string s;
	int dem = 0;
	ifs.open("data2.txt", ios::in);
	while(1) { // cac tu va tan suat torng file data2.txt
		ifs >> s;
		if(ifs.eof()) break;
		list2.search(s);
		dem++;
	}
	ifs.close();
	cout << "\nList 2 :\n";
	list2.show();
	ifs.open("data1.txt", ios::in);
	while(1) { // cac tu va tan suat trong file data1.txt
		ifs >> s;
		if(ifs.eof()) break;
		list1.search(s);
		dem++;
	}
	ifs.close();
	cout << "\nList 1 :\n";
	list1.show();
	ofs.open("ketqua.txt", ios::out);
	while(list1.top >= 0 ) {
		int topTmp = list2.top;
		while(topTmp >= 0 ) {
			if(list1.list[list1.top].s == list2.list[topTmp].s )break;
			topTmp--;
		}
		if(topTmp < 0) {
			ofs << list1.list[list1.top].s << " " << (float)list1.list[list1.top].num/dem << endl;
		}
		list1.top--;
	}
	ofs.close();
	
	
//	ofs.open("ketqua.txt", ios::out);
//	while(list.top >= 0) {
//		ofs << list.list[list.top].s << " " << (float)list.list[list.top].num/dem << endl;
//		list.top--;
//	} 
//	list.show();
	
	return 0;
}
