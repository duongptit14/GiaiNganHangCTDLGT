#include<iostream>
using namespace std;

int sequential_Search(int a[],int n,int x){// Tim kiem tuyen tinh
	for(int i=1;i<=n;i++){
		if(a[i]==x)	return i;
	}
}

int binary_Search(int a[],int n,int x,int f,int e){
	int mid=(f+e)/2;	
	while(f<=e){
		if(x>a[mid])	f=mid+1;
		else if(x<a[mid])	e=mid-1;
		else if(x == a[mid])	return mid;	
		mid=(f+e)/2;
	}
	return -1;
}
 
int fibo_Search(int a[], int n, long x){ 
    int inf=0, pos, k;
    static int kk= -1, nn=-1,
	fib[]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987,
	1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418,
	317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 
	24157817, 39088169, 63245986, 102334155, 165580141};
	if(nn!=n)
	{ 
   		k=0;
    	while(fib[k]<n) k++;
    	kk=k;
   		nn=n;
	}
	else
    	k=kk;
	while(k>0)
	{
    	pos=inf+fib[--k];
    	if((pos>=n)||(x<a[pos]));
    	else if (x>a[pos])
    	{
      	  inf=pos+1;
       	 k--;
    	}
 		 else {
        	return pos;
    	}
	}
    return -1;
}

int interpolation_search (int a[], int n, int x)	// Tim kiem noi suy
{
  int low = 0;
  int high = n - 1;
  int mid;
  while (a[low] <= x && a[high] >= x)
  {
    mid = low + ((x - a[low]) * (high - low)) / (a[high] - a[low]);
    if (a[mid] < x)
    {
      low = mid + 1;
    }
    else if (a[mid] > x)
    {
      low = mid - 1;
    }
    else
    {
      return mid;
    }
  }
  if (a[low] == x)
  {
    return low;
  }
  else
  {
    return -1;
  }
}

int main(){
	int n=7;
	int a[7]={1,3,4,6,9,10,20};
	cout<<sequential_Search(a,n,5)<<"\n";
	cout<<binary_Search(a,n,6,0,6)<<"\n";
	cout<<fibo_Search(a,n,6)<<"\n";
	cout<<interpolation_search(a,n,6)<<"\n";
	
	return 0;
}
