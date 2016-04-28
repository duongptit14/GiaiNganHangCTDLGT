#include <iostream>

using namespace std;
typedef struct {
	char value;
}Item;
struct Node {
	Item it;
	Node *next;
};
class Stack {
	public:
		Node *st;
		Node* create(char value);
		void pop();
		char top();
		void push(char value);
		void show();
		Stack() {
			st = NULL;
		}
};
Node* Stack::create(char value) {
	Node* tmp = new Node();
	tmp->it.value = value;
	tmp->next = NULL;
	return tmp;
}
void Stack::pop() {
	if( st != NULL ) st = st->next;
}
char Stack::top() {
	return st->it.value;
}
void Stack::push(char value) {
	Node *tmp = create(value);
	if(st == NULL ) {
		st = tmp;
		st->next = NULL;
	}
	else {
		Node *q = st;
		st = tmp;
		st->next = q;
	}
}
void Stack::show() {
	Node *q = st;
	while(q!=NULL) {
		cout << q->it.value;
		q = q->next;
	}
	cout << endl;
}
void convert( int so , int he) {
	char F[] = "0123456789ABCDEFGHIKLM";
	Stack st;
	while(so) {
		st.push(F[ so%he]);
		so /= he;
	}
	st.show();
}
int main() {
	int so, he;
	cout << "Nhap so , he :"; cin >> so >> he;
	convert(so,he);
	
	return 0;
}
