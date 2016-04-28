#include <iostream>
#include <cstdlib>
#include <sstream> 
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
		string toString();
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
string Stack::toString() {
	string res = "";
	Node *q = st;
	while(q!=NULL) {
		res += q->it.value;
		q = q->next;
	}
	return res;
}
string convert( int so , int he) {
	char F[] = "0123456789ABCDEFGHIKLM";
	Stack st;
	while(so) {
		st.push(F[ so%he]);
		so /= he;
	}
	string res = st.toString();
	return res;
}
bool isThuanNghich(string s) {
	int len= s.length();
	int left = 0, right = len-1;
	while(left <= right ) {
		if( s[left] != s[right]) return false;
		left++; right--;
	}
	return true;
}
string toString(int n) {
	stringstream ss;
	ss << n;
	return ss.str();
}
void process() {
	int so, he;
	cout << "Nhap so va he :"; cin >> so >> he;
	string strNum = toString(so);
	string strConvert = convert(so,he);
	if(isThuanNghich(strNum) && isThuanNghich(strConvert)) cout << so << " " << strConvert << endl;
}
int main() {
	int test; cin >> test;
	while(test--) {
		process();
	}
	return 0;
}
