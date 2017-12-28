// Stack - Array
#include <iostream>
#define MAX 1000

using namespace std;

struct Node{
	int a[MAX];
	int top = 0;
};
class Stack {
public:
	Node st;
	void init() {
		st.top = 0;
	}
	int top() {
		return st.a[st.top];
	}
	bool empty() {
		return st.top == 0;
	}
	bool full() {
		return st.top == MAX;
	}
	void push(int x) {
		st.top++;
		st.a[st.top] = x;
	}
	int size() {
		return st.top;
	}
	void pop() {
		if( st.top > 0 ) {
			st.a[st.top] = 0;
			st.top--;
		}
	}
	void show() {
		if( st.top == 0 ) {
			cout << "Stack rong " << endl;
			return;
		}
		cout << "Stack :";
		for( int i = st.top; i>0; i-- ) cout << st.a[i] << " ";
		cout << endl;
	}
};
int main() {
	Stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.show();
	cout << "Size of stack :" << st.size() << endl;;
	if( st.empty()) {
		cout << "Stack rong" << endl;
	}
	else cout << "Stack khong rong" << endl;
	cout << st.top() << endl;
	return 0;
}