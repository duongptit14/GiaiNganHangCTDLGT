#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include<stack>

using namespace std;
int a[100][100];
int deg[100]={0};	
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
			if(a[i][j] == 1)	deg[i] ++;
		}		
	}	
	int sl=0;
	int vt=1;
	for(int i=1;i<=n;i++){
		if(deg[i]%2 == 1){
			sl++;
			vt=i;
		}
	}
	cout<<sl<<"\n";
	if(sl!=0 && sl!=2)	return -1;
	
	return vt;
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
	if(x == -1) cout<<"Khong ton tai duong di euler"<<"\n";
	else{
		Euler_Cycle(x);
		for(int i=sl;i>=1;i--)	cout<<CE[i]<<" ";
	}
	
	
	return 0;
}
