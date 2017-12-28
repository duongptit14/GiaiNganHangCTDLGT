// hang doi uu tien- cai dat bang mang
#include <iostream>
#define MAX 10

using namespace std;
struct Queue {
	int front;
	int end;
	int count;
	int a[MAX];
};
void Init( Queue &q ) {
	q.front = 0;
	q.end = -1;
	q.count = 0;
}
bool IsEmpty( Queue q ) {
	return q.count == 0;
}
bool IsFull( Queue q ) {
	return q.count == MAX;
}
int Size( Queue q ) {
	return q.count;
}
void Push( Queue &q , int x ) {
	if( q.count == 0 ) {
		q.end++;
		q.a[q.end] = x;
		q.count++;
	}
	else {
		int i = q.end;
		while( x < q.a[i] && i >= q.front ) i--;
		for( int j = q.end+1; j > i+1; j-- ) {
			q.a[j] = q.a[j-1];
		}
		q.a[i+1] = x;
		q.end++;
		q.count++;
	}
}
int Top( Queue q ) {
	if( q.count == 0 ) {
		cout << "Queue rong" << endl;
		return 0;
	}
	else return q.a[q.front];
}
void Pop( Queue &q ) {
	q.front++;
	q.count--;
}
void Show( Queue q ) {
	for( int i = q.front; i<= q.end; i++ ) {
		cout << q.a[i] << " ";
	}
	cout << endl;
}
int main() {
	Queue q;
	Init(q);
	Push(q,1);
	Push(q,9);
	Push(q,3);
	Push(q,5);

	Show(q);
	Pop(q);
	Show(q);
	cout << Top(q);
	return 0;
}
