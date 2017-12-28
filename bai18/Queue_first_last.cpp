// Queue with first and last
#include <iostream>

using namespace std;
typedef struct {
	int value;
}Item;
struct Node {
	Item it;
	Node *next;
};
class Queue {
	public:
		Node *q;
		Node *last, *first;
		Queue() {
			q = NULL;
			last = NULL;
			first = NULL;
		}
		Node *create(int value);
		void pop();
		int top();
		bool empty();
		void push(int value);
		void show();
};
Node* Queue::create(int value) {
	Node *tmp = new Node();
	tmp->it.value = value;
	tmp->next = NULL;
	return tmp;
}
void Queue::pop() {
	first = first->next;
	q = first;
}
int Queue::top() {
	return first->it.value;
}
void Queue::push(int value) {
	Node *tmp = create(value);
	if(q == NULL) {
		q = tmp;
		q->next = NULL;
		first = q;
		last = q;
	}
	else {
		last->next = tmp;
		last = last->next;
	}
}
void Queue::show() {
	Node *p = first;
	while(p!=NULL) {
		cout << p->it.value << " ";
		p = p->next;
	}
	cout << endl;
}
int main() {
	Queue q;
	q.push(3);
	q.push(5);
	q.push(7);
//	q.pop();
	q.show();
	
	
	return 0;
}
