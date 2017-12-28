// hang doi - pointer
#include <iostream>
#define MAX 100

using namespace std;
struct Node {
	int value;
	Node *next;
};
struct Queue {
	Node *front;
	Node *end;
	int count;	
};
void Init( Queue &q ) {
	q.front = q.end = NULL;
	q.count = 0;
}
bool IsEmpty( Queue q ) {
	return q.count == 0;
}
bool IsFull( Queue q ) {
	return q.count == MAX;
}
int Top( Queue q ) {
	return q.front->value;
}
Node* MakeNode( int x ) {
	Node *tmp = new Node();
	tmp->value = x;
	tmp->next = NULL;
	return tmp;
}
void Push( Queue &q, int x ) {
	Node *tmp = MakeNode(x);
	if( IsEmpty(q) ) {
		q.front = q.end = tmp;
	}
	else {
		Node *s = q.front;
		while( s->next && s->next->value <= x) s = s->next;
		tmp->next=s->next;
		s->next=tmp;
	}
	q.count++;
}
int Size( Queue q ) {
	return q.count;
}
void Show( Queue q ) {
	Node *tmp = q.front;
	while( tmp ) {
		cout << tmp->value << " ";
		tmp = tmp->next;
	}
	cout << endl;
}
int main() {
	Queue q;
	Init(q);
	Push(q,1);
	Push(q,2);
	Push(q,9);
	Push(q,4);
	Show(q);
	cout << Size(q);
	return 0;
}