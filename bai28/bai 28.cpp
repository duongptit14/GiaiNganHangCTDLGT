#include<iostream>
using namespace std;

void swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}

void selectionSort(int a[], int n){
	for (int i = 0; i < n - 1; i++){
		int min = i;
		for (int j = i + 1; j < n; j++){
			if (a[j] < a[min]){
				min = j;
			}
		}
		if (min != i){
			swap(a[min], a[i]);
		}
	}
}

void insertionSort(int a[], int n){
	for (int i = 1; i < n; i++){
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key){	// tim phan tu dau tien ma < key
			a[j + 1] = a[j];			// dich lui day ve phia sau 1 bit
			j--;
		}
		a[j + 1] = key;
	}
}

void bubbleSort(int a[], int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n - i - 1; j++){
			if (a[j] > a[j + 1]){
				swap(a[j], a[j + 1]);
			}
		}
	}
}

int partition(int a[], int l, int h){
	int x = a[h];
	int i = l - 1;
	for (int j = l; j <= h - 1; j++){
		if (a[j] <= x){
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[h]);
	return i + 1;
}

void quickSort(int a[], int l, int h){
	if (l < h){
		int p = partition(a, l, h);
		quickSort(a, l, p - 1);
		quickSort(a, p + 1, h);
	}
}

void in(int a[], int n){
	for (int i = 0; i < n; i++){
		cout << a[i] << "  ";
	}
	cout << endl;
}

void merge(int a[], int l, int m, int r){

	int n1 = m - l + 1;
	int n2 = r - m;
	int L[100], R[100];
	for (int i = 0; i < n1; i++){
		L[i] = a[l + i];
	}
	for (int i = 0; i < n2; i++){
		R[i] = a[m + 1 + i];
	}

	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2){
		if (L[i] <= R[j]){
			a[k] = L[i];
			i++;
		}
		else{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1){
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < n2){
		a[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int a[], int l, int r){
	if (l < r){
		int m = (l + r - 1) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}


void shell_Sort(int a[], int n, int h[], int k)
{
    int step, i, j;
    int x, len;
    for(step = 0; step < k; step++)    //duyet qua tung buoc nhay
    {
        len = h[step];            // chieu dai cua moi buoc nhay
        for(i = len; i < n; i++)    //duyet cac day con    
        {
            // Luu phan tu cuoi cung de tim vi tri thich hop trong day con
            x = a[i];
            // a[j] dung trc a[i] trong day con
            j=i-len;
            while ((x < a[j]) && (j>= 0))    
            // sap xep dung pp chen
            {
                a[j+len] = a[j];   
                j = j - len;        
            }
            a[j+len] = x;    
        }
    }
}

void ShakerSort(int a[], int n) 
{
    	int Left = 0;
    	int Right = n - 1;
    	int k = 0;
    	while (Left < Right)
    	{
    		for (int i = Left; i < Right; i++)	// dua cac phan tu nho nhat ve dau day
    		{
    			if (a[i] > a[i + 1])
    			{
    				swap(a[i], a[i + 1]);
    				k = i;
    			}
    		}
    		Right = k;
    		for (int i = Right; i > Left; i--)	// dua cac phan tu lon ve cuoi day
    		{
    			if (a[i] < a[i - 1])
    			{
    				swap(a[i], a[i - 1]);
    				k = i;
    			}
    		}
    		Left = k;
    	}
}


void RadixSort(int a[],int n)
{
	int i,b[10000],m=0,exp=1;
		for(i=0;i<n;i++)
		{
			if(a[i]>m)
			m=a[i];
		}
			while(m/exp>0)
			{
      	        int c[10]={0};
        	    for(i=0;i<n;i++)
                	c[a[i]/exp%10]++;
                for(i=1;i<10;i++)
                	c[i]+=c[i-1];
                for(i=n-1;i>=0;i--)
                	b[--c[a[i]/exp%10]]=a[i];
                for(i=0;i<n;i++)
                	a[i]=b[i];
				exp*=10;
 			}	
}  

int main(){
	int a[] = { 1,5, 2, 2,1, 4, 6, 10, 20, 13 };
	int n = 10;
	selectionSort(a, n);
	in(a, n);

	int a2[] = { 1,5, 2, 2,1, 4, 6, 10, 20, 13 };
	insertionSort(a2, n);
	in(a2, n);
	
	int a3[] = { 1,5, 2, 2,1, 4, 6, 10, 20, 13 };
	bubbleSort(a3, n);
	in(a3, n);

	int a4[] = { 1,5, 2, 2,1, 4, 6, 10, 20, 13 };
	quickSort(a4, 0, 9);
	in(a4, n);

	int a5[] = { 1,5, 2, 2,1, 4, 6, 10, 20, 13 };
	mergeSort(a5, 0, 9);
	in(a5, n);

//	int a6[] = { 1,5, 2, 2,1, 4, 6, 10, 20, 13 };
//	heapSort(a6, 10);
//	in(a6, n);
	
	int a7[] = { 1,5, 2, 2,1, 4, 6, 10, 20, 13 };
	int h[4]={5,3,1};
	int k=3;
	shell_Sort(a7, 10,h,k);
	in(a7, n);
	
	
		
	int a8[] = { 1,5, 2, 2,1, 4, 6, 10, 20, 13 };
	ShakerSort(a8,n);
	in(a8, n);
	
	int a9[] = { 1,5, 2, 2,1, 4, 6, 10, 20, 13 };
	RadixSort(a9,n);
	in(a9, n);
	
	return 0;
}
