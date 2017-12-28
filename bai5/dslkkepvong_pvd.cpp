// danh sach lien ket keo vong - code by PVDptit
#include  <iostream>

using namespace std;
struct Node {
	int value;
	Node *next;
	Node *prev;
};
struct List {
	Node *l;
	Node *front;
	Node *end; 
	int count;
};
void Init( List &list ) {
	list.l = NULL;
	list.front = list.end = NULL;
	list.count = 0;
}
Node* MakeNode( int value ) {
	Node *tmp = new Node();
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = NULL;
	return tmp;
}
void Add_Begin( List &list, int value ) {
	Node *tmp = MakeNode(value);
	if( list.l == NULL ) {
		list.l = tmp;
		tmp->next = list.l;
		tmp->prev = list.l;
		list.l->next = list.l;
		list.l->prev = list.l;
	}
	else {
		tmp->next = list.l->next;
		list.l->next = tmp;
		tmp->prev = list.l;
		(tmp->next)->prev = tmp;
	}
	list.count++;
}
void Add_End( List &list, int value ) {
	Node *tmp = MakeNode(value);
	if( list.l == NULL ) {
		list.l = tmp;
		tmp->next = list.l;
		tmp->prev = list.l;
		list.l->next = list.l;
		list.l->prev = list.l;
	}
	else {
		tmp->next = list.l->next;
		list.l->next = tmp;
		tmp->prev = list.l;
		(tmp->next)->prev = tmp;
		list.l = tmp;
	}
	list.count++;
}
void Add_Pos( List &list, int value, int pos ) {
	Node *tmp = MakeNode(value);
	if( list.l == NULL || list.count == 0 ) {
		Add_Begin(list,value);
	}
	else {
		Node *q = list.l->next;
		Node *p = q->next;
		for( int i = 0; i<pos-1; i++ ) {
			q = q->next;
			p = p->next;
		}
		q->next = tmp;
		tmp->prev = q;
		tmp->next = p;
		if(p) p->prev = tmp;
		list.count++;
	}
}
void Del_Begin( List &list ) {
	if( list.l == NULL ) {
		cout << "danh sach rong" << endl;
	}
	else {
		Node *q = (list.l->next)->next;
		list.l->next = q;
		q->prev = list.l;
		list.count--;
	}
}
void Del_End( List &list ) {
	if( list.l == NULL ) {
		cout << "danh sach rong" << endl;
	}
	else {
		Node *q = list.l->next;
		list.l = list.l->prev;
		list.l->next = q;
		q->prev = list.l;
		list.count--;
	}
}
void Del_Pos( List &list , int pos ) {
	if( list.l == NULL ) {
		cout << "danh sach rong" << endl;
	}
	else {
		Node *q = list.l->next;
		Node *p = q->next;
		for( int i = 0; i<pos-1; i++ ) {
			q = q->next;
			p = q->next;
		}
		q->next = p->next;
		(q->next)->prev = q;
		list.count--;
	}
}
Node *Search( List &list, int value ) {
	if( list.l == NULL ) {
		cout << "danh sach rong" << endl;
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
void Sort( List &list ) {
	if( list.l == NULL ) {
		cout << "danh sach rong" << endl;
	}
	else {
		Node *q = list.l->next;
		while( q != list.l ) {
			Node *p = q->next;
			while( p != list.l->next) {
				if( q->value > p->value ) swap(q->value, p->value);
				p = p->next;
			}
			q  =q->next;
		}
	}
}
void Reverse( List &list ) {
	List res;
	Init(res);
	Node *q = list.l->next;
	while( q != list.l ) {
		Add_Begin(res,q->value);
		q = q->next;
	}
	Add_Begin(res,q->value);
	list = res;
}
void Show( List &list ) {
	Node *q = list.l->next;
	while( q!= list.l ) {
		cout << q->value << " ";
		q = q->next;
	}
	cout << q->value << endl;
}
int main() {
	List list;
	Init(list);
	Add_Begin(list,1);
	Add_Begin(list,2);
	Add_Begin(list,3);
	Add_End(list,0);
	Add_End(list,-1);
	Add_Pos(list,9,2);
	Del_Begin(list);
	Del_End(list);
	Del_Pos(list,1);
	Search(list,2)->value = 69;
	Sort(list);
	Show(list);
	Reverse(list);
	Show(list);

	return 0;
}