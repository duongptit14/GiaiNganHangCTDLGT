// double-llist
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
struct Node {
	int value;
	Node *next;
	Node *prev;
};
struct DoubleList {
	Node *dlist;
};
void Init( DoubleList &DL ) {
	DL.dlist = NULL;
}
Node * MakeNode ( int value ) {
	Node *tmp = new Node();
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = NULL;
	return tmp;
}
void Push( DoubleList &DL , int x ) {
	Node *tmp = MakeNode(x);
	if( DL.dlist == NULL ) {
		DL.dlist = tmp;
		DL.dlist->next = NULL;
		DL.dlist->prev = NULL;
	}
	else {
		Node *q = DL.dlist;
		if( DL.dlist->value > x ) {
			tmp->next = DL.dlist;
			q->prev = tmp;
			DL.dlist = tmp;
			return ;
		}
		while( q->next && q->next->value < x ) {
			q = q->next;
		}
		tmp->next = q->next;
		if( q->next ) (q->next)->prev = tmp;
		tmp->prev = q;
		q->next = tmp;

		
	}
}
void Show( DoubleList DL ) {
	Node *q = DL.dlist;
	while(q) {
		cout << q->value << " " ;
		q = q->next;
	}
	cout << endl;
}

int main() {
	DoubleList DL;
	Init(DL);
	Push(DL,7);
	Push(DL,2);
	Push(DL,8);
	Push(DL,0);
	Push(DL,9);
	Push(DL,5);
	// Push
	Show(DL);


	return 0;
}