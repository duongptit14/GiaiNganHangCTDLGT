#include <iostream>
#include <fstream>
#include <stack>
#include <sstream>
using namespace std;
ifstream ifs;
stack <int> st;
bool isNum( string sub ) {
	for( int i = 0; i< sub.length(); i++ ) {
		if( sub[i] < '0' || sub[i] > '9' ) return false;
	}
	return true;
}
int Atoi( string sub ) {
	int res = 0;
	for( int i = 0; i< sub.length(); i++ ) {
		res += (int)(sub[i] - 48 );
	}
	return res;
}
void process(string sub) {
	if( isNum(sub) ) {
		st.push(Atoi(sub));
	}
	else {
		if( sub == "+") {
			int x = st.top();
			st.pop();
			int y = st.top();
			st.pop();
			st.push(x+y);
		}
		else if( sub == "-") {
			int x = st.top();
			st.pop();
			int y = st.top();
			st.pop();
			st.push(y-x);	
		}
		else if ( sub == "*") {
			int x = st.top();
			st.pop();
			int y = st.top();
			st.pop();
			st.push(x*y);
		}
		else if( sub == "/") {
			int x = st.top();
			st.pop();
			int y = st.top();
			st.pop();
			st.push(y/x);
		}
	}
}
int main() {
	ifs.open("hauto.txt", ios::in);
	string str;
	while(!ifs.eof()) {
		getline(ifs, str);
		istringstream iss(str);
		do {
			string sub;
			iss >> sub;
			if( sub == "\0") break;
			process(sub);
		} while( iss );
		cout << st.top();
	}
	return 0;
}