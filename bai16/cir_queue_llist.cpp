// 
#include <iostream>
#define MAX 100

using namespace std;
struct Node {
	int value;
	Node *next;
};
struct Queue {
	Node *q;
	int count;
};
void Init( Queue &queue ) {
	queue.q = NULL;
	queue.count = 0;
}
bool IsEmpty( Queue queue ) {
	return queue.count == 0;
}
bool IsFull( Queue queue ) {
	return queue.count == MAX;
}
void Push( Queue &queue , int value ) {
	Node *tmp = new Node();
	tmp->value = value;
	tmp->next = NULL;
	if( queue.q == NULL ) {
		queue.q = tmp;
		queue.q->next = tmp;
	}
	else {
		tmp->next = queue.q->next;
		queue.q->next = tmp;
	}
}
int Top( Queue queue ) {
	return queue.q->next->value;
}
void Show( Queue queue ) {
	Node *tmp = queue.q->next;
	while(tmp != queue.q ) {
		cout << tmp->value << " ";
		tmp = tmp->next;
	}
	cout << tmp->value << endl;
}
int main() {
	Queue queue;
	Init(queue);
	Push(queue,1);
	Push(queue,2);
	Push(queue,3);
	Push(queue,4);
	Show(queue);


	return 0;
}