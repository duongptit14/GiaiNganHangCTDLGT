#include <iostream>
#include <string.h>
using namespace std;
void reverse(char str[], int index, int size){
	char temp = str[index];
	str[index] = str[size - index];
	str[size - index] = temp;
	if (index == size / 2) return;
	reverse(str, index + 1 , size);
}
int main(){
	char X[] ="ABCDEF";int size = strlen(X);
	reverse(X, 0, size - 1 );
	cout<<"Ket qua is: \n"<<X;
	 return 0;
}
