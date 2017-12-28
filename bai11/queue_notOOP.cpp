// queue - Array - not OOP
#include <iostream>
#define MAX 5

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
bool IsFull( Queue q ) {
	return q.count == MAX;
}  
bool IsEmpty( Queue q ) {
	return q.count == 0;
}
void Pop( Queue &q ) {
	if( q.count == 0 ) {
		cout << "Queue rong !" << endl;
	}
	else {
		q.front++;
		q.count--;
	}
}
int Front( Queue q ) {
	return q.a[q.front];
}
int End( Queue q ) {
	return q.a[q.end];
}
void Push( Queue &q, int x ) {
	q.end++;
	q.a[q.end] = x;
	q.count++;
}
void Show( Queue &q ) {
	for( int i = q.front; i<= q.end; i++ ) cout << q.a[i] << " ";
	cout << endl;
}
void CurShow( Queue q ) {
	for (int i=q.front, j=0; j<q.count; j++, i = (i+1) % MAX) cout << q.a[i] << " ";
	cout << endl;
}
 void CurPush( Queue &q, int x ) { 
 	q.end = (q.end+1) % MAX ; // neu end dang o vi tri max-1 , thi ke tiep n se nhay ve 0
 	q.a[q.end] = x;
 	q.count++;
 }
void CurPop( Queue &q ) {
	q.front = (q.front+1) % MAX ; // neu front dang o max-1 thi ke tiep n se pop o 0
	q.count--;
}
int main() {
	Queue q;
	Init(q);
	CurPush(q,1);
	CurPush(q,2);
	CurPush(q,3);
	CurPush(q,4);
	CurPop(q);
	CurShow(q);
	// Show(q);

	return 0;
}