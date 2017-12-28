#include <iostream>

using namespace std;
int n, OK = 1, a[100];
void init() {
	cout << "Nhap n = "; cin >> n;
	for( int i = 1; i<=n; i++) a[i] = i;
}
void result() {
	for( int i = 1; i<=n; i++) cout << a[i] << " ";
	cout << endl;
}
void sinh() {
    int i=n-1;
    while(i>0 && a[i]>a[i+1]) i--;
        if(i>0){   
			int j=n;
                while(j>0 && a[i]>a[j])   j--;
                int tmp=a[i];
				a[i]=a[j];	a[j]=tmp;	
                    
            	int r=i+1, s=n;
                while(r<=s){
                    int tmp=a[r];	a[r]=a[s];	a[s]=tmp;
                    r++;	s--;
                }
                       
            }
        else    OK=0;
}
void process() {
	init();
	while(OK) {
		result();
		sinh();
	}
}
int main() {
	process();
	return 0;
}
