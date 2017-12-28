#include <iostream>
#include <stack>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#define MAX 10000

using namespace std;
stack <char> st;
ifstream ifs;
bool isNum(string s) {
	for( int i = 0; i< s.length(); i++ ) {
		if( s[i] < '0' || s[i] > '9') return false;
	}
	return true;
}
int GetPriority(char op)
{
    if (op == '*' || op == '/' || op == '%')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}
int GetPriority(string op) {
	if (op == "*" || op == "/" || op == "%")
        return 2;
    if (op == "+" || op == "-")
        return 1;
    return 0;
}
void process(string x) {
	if( x == "(" ) st.push('(');
	else if( isNum(x)) {
		cout << x << " ";
		// if( st.empty()) {

		// }
		// else {
		// 	cout << st.top() << endl;
		// }
	}
	else if ( x == ")") {
		char c = st.top();
		while( c != '(') {
			cout << c << " ";
			st.pop();
			c = st.top();
		}
		st.pop();
		return;
	}
	else {
		if( !st.empty()) {
			char c = st.top();
			if( GetPriority(x) >= GetPriority(c)) {
				c = x[0];
				st.push(c);
			}
			else if( GetPriority(x) < GetPriority(c)) {
				cout << c;
				st.pop();
				c = x[0];
				st.push(c);
			}
		}
		else if( st.empty()) {
			char c = x[0];
			st.push(c);
		}
	}

}
int main() {
	ifs.open("trungto_hauto.txt", ios::in);
	if( !ifs.is_open()) {
		cout << "Erro File !" << endl;
		return 0;
	}
	string str;
	while(!ifs.eof()) {
		getline(ifs,str);
		istringstream iss(str);
    	do
    	{
      		string sub;
        	iss >> sub;
        	if( sub == "\0") break;
        	process(sub);

    	} while (iss);
    	while(!st.empty()) {
    		cout << st.top() << " ";
    		st.pop();
    	}
    	cout << endl;
	}

	return 0;
}