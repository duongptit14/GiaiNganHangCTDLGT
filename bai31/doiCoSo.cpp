#include <iostream>

using namespace std;
void convert( int n, int b ) {
	if( n >= b ) convert(n/b, b);
	cout << (char)(n%b)["0123456789ABCDEFGHIKLMNOP"];
}
int main() {
	convert(10,2);


	return 0;
}