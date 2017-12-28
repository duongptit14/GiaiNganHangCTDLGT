// Stack - STL
#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack <int> st;
	// kiem tra tinh rong
	if( st.empty()) {
		cout << "stack rong" << endl;
	}
	else cout << "stack khong rong" << endl;
	// kiem tra tinh day
	//lay kich co cua stack
	cout << st.size() << endl;
	// lay phan tu o dau stack
	if( !st.empty() )cout << st.top() << endl;
	// dua phan tu vao stack
	st.push(1); 

	return 0;
}