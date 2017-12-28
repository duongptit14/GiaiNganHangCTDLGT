#include <iostream>
  
using namespace std;
  
int soNguGiac(int k ) {
    return k*(3*k-1)/ 2;
  
}
  
void calculate() {
    int number = 5 ;
    
    int f[10000] ;
    f[0] = 1 ;
  
    for(int i = 1 ; i<=number ; i++) {
        int s = 1 ;
        int sumA = 0 ;
        int sumB = 0 ;
        int k = 1;
        while ( soNguGiac(k) <= i ) {
            sumA+= s* f[i - soNguGiac(k)] ;
            if( soNguGiac(-k) <= i )
            sumB += s* f[i - soNguGiac(-k) ] ;
            k++ ;
            s= -s ;
        }
        f[i] = sumA+sumB ;
        cout<<f[i]<<endl ;
  
    }
    cout<<"Tong so cach " <<f[number]<<endl ;
  
}
int main()
{
    calculate() ;
    return 0;
}