#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ofstream ofs;
typedef struct {
	string s;
	int num;
} Item;
struct Node {
	Item it;
	Node *next;
};
class Single_LList {
	public:
		Node *list;
		Node* create(string s);
		void search(string s);
		void add_begin(string s);
		void show();
		bool empty() {
			return list==NULL;
		}
		Single_LList() {
			list = NULL;
		}
};
Node* Single_LList::create(string s) {
	Node *tmp = new Node();
	tmp->it.s = s;
	tmp->it.num = 1;
	tmp->next = NULL;
	return tmp;
}
void Single_LList::add_begin(string s) {
	Node *tmp = create(s);
	if( list == NULL ) {
		list = tmp;
		list->next = NULL;
	}
	else {
		Node *p = list;
		list = tmp;
		list->next = p;
	}
}
void Single_LList::search(string s) {
	if(list==NULL) {
		add_begin(s);
	}
	else {
		bool isFind = false;
		Node* p = list;
		while(p!=NULL) {
			if(p->it.s == s) {
				p->it.num++; 
				isFind = true;
				break;
			}
			p = p->next;
		}
		if(!isFind) {
			add_begin(s);
		}
	}
}
void Single_LList::show() {
	if(list==NULL) {
		cout << "non"; return;
	}
	Node*p = list;
	while(p!=NULL) {
		cout << p->it.s << " " << p->it.num << endl;
		p = p->next ;
	}
	cout << endl;
}
int main() { 
	Single_LList list;
	ifstream ifs("data1.txt", ios::in);
	string s;
	int dem = 0;
	while(1) {
		ifs >> s;
		if(ifs.eof()) break;
		dem++;
		list.search(s);
	}
	ifs.close();
	ifs.open("data2.txt", ios::in);
	while(1) {
		ifs >> s;
		if(ifs.eof()) break;
		dem++;
		list.search(s);
	}
	ifs.close();
	ofstream ofs("ketqua.txt", ios::out);
	Node *p = list.list;
	while(p!=NULL) {
		ofs << p->it.s << " " << (float)p->it.num/dem << endl;
		p = p->next;
	}
	ofs.close();
	return 0;
}
