#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include<stack>

using namespace std;
int a[100][100];

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
	
	ifstream ifs("DSK.txt", ios::in);
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
	
	Euler_Cycle(1);
	for(int i=sl;i>=1;i--)	cout<<CE[i]<<" ";
	
	return 0;
}
