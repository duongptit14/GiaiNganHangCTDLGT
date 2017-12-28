#include<iostream>
using namespace std;
int n,a[100];
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
	
}

//thuat toan SelectionSort
void Selectionsort(int a[], int n)
{
  int min;
  for(int i=0;i<n-1;i++)
  {
      min=i;
      for(int j=i+1;j<n;j++)
        if(a[j]<a[min]) min=j;  // Tìm duoc vi trí chua giá tri nho nhat
      		swap(a[min],a[i]);        // Ðoi cho min cho i
  }
  for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<'\n';
}
//thuat toan Insertionsort
void Insertionsort(int a[], int n)
{
     int i,tg,x;
     for (i=1;i<n;i++)
      {
        tg=a[i];
        x=i-1;//xet nhung phan tu o sau no
        while((x>=0)&&(a[x]>tg)) //tim vi tri tich hop cho tg de dat vao
            {
            a[x+1] = a[x];
            x--;
            }
        a[x+1] =tg;
     }
    for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<'\n';
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	Insertionsort(a,n);
	Selectionsort(a,n);
}
