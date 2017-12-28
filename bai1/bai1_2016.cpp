// 1 - danh sach lien ket don
#include <iostream>
#include <fstream>
using namespace std ;
struct Node {
	int value;
	Node* next;
};
class LinkedList {
	public:
		Node *list;
		void init() {
			list = NULL;
		}
		void push_front(int value);
		void push_back(int value);
		void push_pos(int value, int pos);
		void del_front();
		void del_back();
		void del_pos(int pos);
		Node* search(int value);
		void duyet();
		void Sort();
		void dao();
};
void LinkedList::push_front(int value) {
	Node *tmp = new Node();
	tmp->value = value;
	tmp->next = NULL;
	if( list == NULL ) {
		list = tmp;
		list->next = NULL;
	}
	else {
		tmp->next = list;
		list = tmp;
	}
	
}
void LinkedList::push_back(int value) {
	Node *tmp = new Node();
	tmp->value = value;
	tmp->next = NULL;
	if( list == NULL ) {
		list = tmp; return ;
	}
	Node *q = list;
	while(q->next != NULL ) {
		q = q->next;
	}
	q->next = tmp;
}
void LinkedList::duyet() {
	if( list == NULL ) {
		cout << "List rong !" << endl;
		return ;
	}
	Node *q = list;
	cout << "List :";
	while(q!=NULL) {
		cout << q->value << " ";
		q = q->next;
	}
}
void LinkedList::push_pos(int value, int pos) {
	Node *tmp = new Node();
	tmp->value = value;
	tmp->next = NULL;
	Node *q = list;
	Node *p = new Node();
	for( int i = 0; i< pos-1; i++ ){
		q = q->next;
		p = q->next;
	}
	q->next = tmp;
	tmp->next = p;
}
void LinkedList::del_front() {
	if( list == NULL ) return ;
	list = list->next;
}
void LinkedList::del_back() {
	if( list== NULL ) return ;
	Node *q = list;
	while(q->next->next != NULL ) {
		q = q->next;
	}
	q->next = NULL;
}
void LinkedList::del_pos( int pos ) {
	Node *q = list;
	Node *p = new Node();
	for( int i = 0; i< pos-1; i++ ) {
		q = q->next;
		p = p->next;
	}
	q->next = p->next;
}
Node* LinkedList::search( int value ) {
	Node *q = list;
	if( list == NULL ) return NULL;
	while( q != NULL ) {
		if( q->value == value ) return q;
		q = q->next;
	}
	cout << "Khong thay x";
	return NULL;
}
void LinkedList::Sort() {
	Node *i = list;
	while( i->next != NULL ) {
		Node* j = i->next;
		while( j != NULL ) {
			if( i->value < j->value ) {
				int tmp = i->value;
				i->value = j->value;
				j->value = tmp;
			}
			j = j->next;
		}
		i = i->next;
	}
}
void LinkedList::dao() {
	Node *res = new Node();
	res->value = list->value;
	res->next = NULL;
	list = list->next;
	while( list != NULL ) {
		Node *q = new Node();
		q->value = list->value;
		q->next = res;
		res = q;
		list = list->next;
	}
	list = res;	
}
int main() {
	LinkedList list;
	list.init();
	list.push_front(2);
	list.push_front(3);
	list.duyet();
	ifstream ifs("P.txt", ios::in);
	int tmp;
	while(!ifs.eof()) {
		ifs >> tmp;
		list.push_front(tmp);
	}
	list.duyet();
	return 0;
}
