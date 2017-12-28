#include <iostream>

using namespace std;
struct Node {
	int value;
	Node* next;
	Node* prev;
};
class DouList {
	public:
		Node *list;
		void init() {
			list = NULL;
		}
		Node* createNode(int value) {
			Node *tmp = new Node();
			tmp->value = value;
			tmp->next = NULL;
			tmp->prev = NULL;
			return tmp;
		}
		void push_front(int value);
		void push_back(int value);
		void push_pos(int value, int pos);
		void del_front();
		void del_back();
		void del_pos(int pos);
		Node* search(int value);
		void Sort();
		void dao();
		void show();
};
void DouList::push_front(int value) {
	Node* tmp = createNode(value);
	if( list == NULL ) {
		list = tmp;
		list->next = NULL;
		list->prev = NULL;
	}
	else {
		tmp->next = list;
		list->prev = tmp;
		list = tmp;
	}
}
void DouList::push_back(int value) {
	Node *tmp = createNode(value);
	if( list == NULL ) {
		list = tmp;
		list->next = NULL;
		list->prev = NULL;
	}
	else {
		Node *q = list;
		while(q->next) q = q->next;
		q->next = tmp;
		tmp->prev = q;
	}
}
void DouList::push_pos(int value, int pos) {
	Node *tmp = createNode(value);
	Node *q = list;
	Node *p = new Node();
	for( int i = 0; i< pos-1; i++ ) {
		q = q->next;
		p = q->next;
	}
	q->next = tmp;
	tmp->prev = q;
	tmp->next = p;
	if(p) p->prev = tmp;
}
void DouList::del_front() {
	if(list) {
		list = list->next;
		list->prev = NULL;
	}
}
void DouList::del_back() {
	if( list == NULL ) return;
	Node *q = list;
	if( q->next == NULL ) {
		list = NULL; return ;
	}
	while(q->next->next) q = q->next;
	q->next = NULL;
}
void DouList::del_pos(int pos) {
	if( list == NULL ) return;
	if( pos == 0 ) {
		del_front();
		return;
	}
	Node *q = list;
	Node *p = q->next;
	for( int i = 0; i< pos-1; i++ ) {
		q = q->next;
		if( q == NULL ) return;
		p = q->next;
	}
	q->next = p->next;
	p->next->prev = q;
}
Node* DouList::search(int value) {
	Node *q = list;
	if( list == NULL ) return NULL;
	while( q ) {
		if( q->value == value ) return q;
		q = q->next;
	}
	return NULL;
}
void DouList::dao() {
	Node *res = new Node();
	while(list) {
		Node *tmp = createNode(list->value);
		tmp->next = res;
		res->prev = tmp;
		res = tmp;
		list = list->next;
	}
	list = res;
	del_back();
}
void DouList::Sort() {
	Node *i = list;
	while(i->next) {
		Node *j = i->next;
		while(j) {
			if( i->value > j->value ) {
				int tmp = i->value;
				i->value = j->value;
				j->value = tmp;
			}
			j = j->next;
		}
		i = i->next;
	}
}
void DouList::show() {
	Node *q = list;
	while(q) {
		cout << q->value << " ";
		q = q->next;
	}
	cout << endl;
}
int main() {
	DouList list;
	list.init();
	list.push_front(3);
	list.push_front(4);
	list.push_front(5);
	list.push_back(2);
list.show();
	list.push_pos(6,3);
	list.show();
	list.push_pos(7,4);
//	list.del_front();
//	list.del_front();
//	list.del_back();
//	list.del_back();
//	list.del_back();
	list.show();
//list.del_pos(1);
	list.search(3)->value = 12;
	list.show();
	list.dao();
//	list.del_back();
	list.show();
	list.Sort();
	list.show();
	list.del_pos(0);
	list.show();
	
	return 0;
}
