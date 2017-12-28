// danh sach lien ket don vong - code by PVDptit
#include <iostream>
#include <cstring>

using namespace std;
struct Node {
	int value;
	Node *next;
};
struct List {
	Node *l;
	Node *front;
	Node *end;
	int count;
};
void Init( List &list) {
	list.l = NULL;
	list.front = list.end = NULL;
	list.count = 0;
}
Node *MakeNode ( int value ) {
	Node *tmp = new Node();
	tmp->value = value;
	tmp->next = NULL;
	return tmp;
}
void Add_Begin(List &list, int value ) {
	Node *tmp = MakeNode(value);
	if( list.l == NULL ) {
		list.l = tmp;
		tmp->next = list.l;
	}
	else {
		tmp->next = list.l->next;
		list.l->next = tmp;
	}
	list.count++;
}
void Add_End(List &list, int value ) {
	Node *tmp = MakeNode(value);
	if( list.l == NULL ) {
		list.l = tmp;
		tmp->next = list.l;
	}
	else {
		tmp->next = list.l->next;
		list.l->next = tmp;
		list.l = tmp;
	}
	list.count++;
}

void Add_Pos( List &list, int value , int pos ) {
	if( pos > list.count ) {
		cout << "Khong chen duoc" << endl;
		return ;
	}
	Node *tmp = MakeNode(value);
	if(pos == 0 || list.l == NULL ) {
		Add_Begin(list,value);
	}
	// else if( pos == count ) { // truong hop chen vao cuoi
	// 	Add_End(value);
	// }
	else {
		Node *q = list.l->next;
		Node *p = q->next;
		for( int i = 0; i<pos-1; i++ ) {
			q = q->next;
			p = q->next;
		}
		q->next = tmp;
		tmp->next = p;
		list.count++;
	}
}
void Del_Begin( List &list ) {
	if( list.l == NULL ) {
		cout << "danh sach rong" << endl;
	}
	else {
		list.l->next = (list.l->next)->next;
	}
	list.count--;
}
void Del_End( List &list ) {
	if( list.l == NULL ) {
		cout << "danh sach rong" << endl;
	}
	else if( list.count == 1 ) {

	}
	else {
		Node *q = list.l->next;
		while( q->next != list.l ) {
			q = q->next;
		}
		q->next = list.l->next;
		list.l = q;
		list.count--;
	}
}
void Del_Pos( List &list, int pos ) {
	if( list.l == NULL ) {
		cout << "danh sach rong" << endl;
	}
	else {
		Node *q = list.l->next;
		Node *p = q->next;
		for( int i = 0; i< pos-1; i++ ) {
			q = q->next;
			p = q->next;
		}
		q->next = p->next;
		list.count--;
	}
}
Node *Search( List list, int value ) {
	if( list.l == NULL ) {
		return NULL;
	}
	else {
		Node *q = list.l->next;
		while( q != list.l ) {
			if( q->value == value ) return q;
			q = q->next;
		}
		if( q->value == value ) return q;
	}
	return NULL;
}
void Show( List list) {
	if( list.l == NULL ) {
		cout << "danh sach rong" << endl;
		return;
	}
	Node *q = list.l->next;
	while ( q != list.l ) {
		cout << q->value << " ";
		q = q->next;
	}
	cout << q->value ;
	cout << endl; 
}
void Sort(List &list) {
	if( list.l == NULL || list.count == 1 ) {
		cout << "khong sap xep" << endl;
		return;
	}
	Node *q = list.l->next;
	while(q != list.l ) {
		Node *p = q->next;
		while(p != list.l->next ) {
			if( q->value > p->value ) {
				// cout << "swap" << endl;
				// cout << q->value << " " << p->value << endl;
				swap(q->value, p->value);
			}
			p = p->next;
		}
		q = q->next;
	}
}
void Reverse( List &list ) {
	List res;
	Init(res);
	Node *q = list.l->next;
	while(q != list.l ) {
		Add_Begin(res,q->value);
		q = q->next;
	}
	Add_Begin(res,q->value);
	list = res;
}
int main() {
	List list;
	Init(list);
	Add_Begin(list,1);
	Add_Begin(list,2);
	Add_Begin(list,3);
	Add_Begin(list,4);
	Add_Begin(list,5);
	Search(list,4)->value = 9;
	Sort(list);
	Show(list);
	Reverse(list);
	Show(list);
	return 0;
}