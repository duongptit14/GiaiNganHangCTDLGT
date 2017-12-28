#include<iostream>
using namespace std;
int main()
{
    int f[101][101];
    int w[101],v[101];
    int n;
    int kl;
    cin>>n>>kl;//so luong do vat va kho^i' luong cua balo^
    for (int i=1;i<=n;i++)
        cin>>w[i]>>v[i];//trong luong va gia tri cua tung do vat
    for (int i=1;i<=kl;i++)
        f[0][i]=0;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=kl;j++)
        {
           f[i][j]=f[i-1][j];
          if (w[i]<=j&&f[i][j]<v[i]+f[i-1][j-w[i]])  f[i][j]=v[i]+f[i-1][j-w[i]];
     }
    cout<<f[n][kl]<<endl;//ket wa?
    return 0;
}