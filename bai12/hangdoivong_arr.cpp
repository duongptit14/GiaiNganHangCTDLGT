// hàng đợi vòng cài đặt bằng mảng
#include <iostream>
#define MAX 100
using namespace std;

struct Queue {
	int a[500];
	int count;
	int front;
	int end;
};
void Init( Queue &q ) {
	q.count = 0;
	q.front = 0;
	q.end = -1;
}
bool IsEmpty( Queue q ) {
	return q.count == 0;
}
bool IsFull( Queue q ) {
	return q.count == MAX;
}
void Push( Queue &q, int value ) {
	q.end = (q.end+1) % MAX;
	q.a[q.end] = value;
	q.count++;
}
int Size( Queue q ) {
	return q.count;
}
int Top( Queue q ) {
	return q.a[q.front];
}
void Show( Queue q ) {
	if( q.count == 0 ) {
		cout << "hang doi rong" << endl;
	}
	else {
		for( int i = q.front, j = 0 ; j < q.count; j++ , i = (i+1)%MAX ) {
			cout << q.a[i] << " ";
		}
		cout << endl;
	}
}
int main() {
	Queue q;
	Init(q);
	Push(q,2);
	Push(q,3);
	Show(q);

	return 0;
}