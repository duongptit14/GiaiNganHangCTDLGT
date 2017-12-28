#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include<stack>

using namespace std;
int a[100][100];
int deg1[100]={0};	//deg+
int deg2[100]={0};	//deg-
struct node{
	int data;
	node *phead, *ptail, *next;
};

typedef struct node NODE;
typedef struct node LIST;

void creatList(LIST &L){
	L.phead = L.ptail = NULL;
}

void push(LIST &L,int x){
	NODE *p = new NODE();
	p->data = x;
	p->next = NULL;
	if(L.phead == NULL){
		L.phead = L.ptail = p;
	}else{
		L.ptail->next = p;
		L.ptail = p;
	}
}
int n;
LIST L[20];

int daxet[100] = {0};
int CE[100];
int sl=0;

int setUp_deg(){
	for(int i=1 ;i<=n; i++){
		for(int j=1;j<=n;j++){
			if(a[i][j] == 1)	deg1[i] ++;
			if(a[j][i] == 1)	deg2[i] ++;
		}
		
	}	
	
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(deg1[i] - deg2[i] == deg1[j] - deg2[j])	return i;
			if(deg1[j] - deg2[j] == deg2[i] - deg1[i])	return i;
		}
	}
	return 0;
}

void Euler_Cycle(int i){
	stack <int > S;
	S.push(i);
	while(!S.empty()){
		int x = S.top();
		int j;
		for(j=1;j<=n;j++){
			if(a[x][j] == 1){
				S.push(j);
				a[x][j] = 0;
				a[j][x] = 0;
				break;
			}
		}
		if(j>n){
			S.pop();
			sl++;
			CE[sl] = x;
		}
	}	
}


int main() {
	
	for(int i=1;i<=n;i++)	creatList(L[i]);
	
	ifstream ifs("euler_cohuong.txt", ios::in);
	ifs >> n;
	char tmp[100];
	ifs.getline(tmp,1);
	int i = 1;
	while(!ifs.eof()) {
		ifs.getline(tmp,100);	
		char *p = strtok(tmp, " ");
		while(p!=NULL) {
			string tmp2 = (string)p;
			int num = atoi(tmp2.c_str());
			a[i][num]++;
			push(L[i],num);
			p = strtok(NULL, " ");
		}
		i++;
	}
	
	ifs.close();
		
	int x = setUp_deg();
	if(x == 0) cout<<"Khong ton tai duong di euler"<<"\n";
	else{
		Euler_Cycle(x);
		for(int i=sl;i>=1;i--)	cout<<CE[i]<<" ";
	}
	
	
	return 0;
}
