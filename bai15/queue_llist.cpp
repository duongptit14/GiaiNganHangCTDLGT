// Queue_LList
#include <iostream>
#define MAX 10000

using namespace std;
struct Node {
	int value;
	Node *next;
};
class Queue {
public:
	Node *q;
	Queue() {
		q = NULL;
	}
	void push(int value) {
		Node *tmp = new Node();
		tmp->value = value;
		tmp->next = NULL;
		if( q == NULL ) {
			q = tmp;
			q->next = NULL;
		}
		else {
			Node *p = q;
			while(p->next) {
				p = p->next;
			}
			p->next = tmp;
		}
	}
	int size() {
		int res= 0;
		Node *p = q;
		while(p) {
			p = p->next;
			res++;
		}
		return res;
	}
	void pop() {
		if( q != NULL ) q = q->next;
		else cout << "Queue rong !" << endl;
	}
	bool empty() {
		return q == NULL;
	}
	bool full() {
		return size() == MAX;
	}
	void show() {
		Node *tmp = q;
		while(tmp) {
			cout << tmp->value << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
};
int main() {
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	// q.pop();
	q.show();
	cout << q.size();

	return 0;
}