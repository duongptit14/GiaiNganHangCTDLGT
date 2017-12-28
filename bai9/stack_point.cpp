#include <iostream>

using namespace std;
struct Node {
	int value;
	Node *next;
};
class Stack {
	public:
	Node *st;
	Stack() {
		st = NULL;
	}
	Node* create_node(int x) {
		Node* tmp = new Node();
		if( tmp == NULL ) {
			cout << "Khong du bo nho"; return 0;
		}
		tmp->value = x;
		tmp->next = NULL;
		return tmp;
	}
	void init() {
		st = NULL;
	}
	bool empty() {
		return st==NULL;
	}
	void pop() {
		st = st->next;
	}
	void push( int x) {
		Node *tmp ;
		tmp = create_node(x);
		if( st == NULL ) {
			st = tmp; st->next = NULL;
		}
		else {
			tmp->next =st;
			st = tmp;
		}		
	}
	int top() {
		return st->value;
	}
	void show() {
		Node* tmp = new Node();
		tmp = st;
		if(tmp == NULL) {
			cout << "Stack rong"; return ;
		}
		while(tmp!=NULL) {
			cout << tmp->value << " ";
			tmp = tmp->next;
		}
	}
};
int main() {
	Stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.show();
	cout << st.top() << endl;
	st.pop();
	st.show();
	return 0;
}
