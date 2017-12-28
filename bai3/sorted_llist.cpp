// sorted linkedlist
#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;
ifstream ifs;
struct Node {
	int value;
	Node *next;
};
struct List {
	Node *l;
};
void Init( List &list ) {
	list.l = NULL;
}
bool IsEmpty( List list ) {
	return list.l == NULL;
}
Node* MakeNode( int value ) {
	Node *tmp = new Node();
	tmp->value = value;
	tmp->next = NULL;
	return tmp;
}
void Push( List &list , int x ) {
	Node *tmp = MakeNode(x);
	if( list.l == NULL ) {
		list.l = tmp;
		list.l->next = NULL;
	}
	else {
		if( list.l->value > x ) {
			tmp->next = list.l;
			list.l = tmp;
			return ;
		}
		Node *q = list.l;
		while( q->next && q->next->value < x ) {
			q = q->next;
		}
		tmp->next = q->next;
		q->next = tmp;
	}
}
void Show( List list ) {
	Node *q = list.l;
	while(q) {
		cout << q->value << " " ;
		q = q->next;
	}
}
void Pop_Front( List &list ) {
	list.l = list.l->next;
}
void Pop_End( List &list ) {
	Node *q = list.l;
	while(q->next->next) {
		q = q->next;
	}
	q->next = NULL;

}
int main() {
	List list;
	Init(list);
	ifs.open("input.txt", ios::in);
	int tmp;
	while(!ifs.eof()) {
		ifs >> tmp;
		Push(list,tmp);
	}
	Show(list);
	return 0;
}