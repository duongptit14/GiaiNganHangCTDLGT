#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include<queue>

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

void BFS(int i){
	queue <int > Q;
	Q.push(i);
	daxet[i]=1;
	while(!Q.empty()){
		int s = Q.front();
		Q.pop();
		NODE *p = L[s].phead;
		while(p){
			if(!daxet[p->data]){
				Q.push(p->data);
				daxet[p->data] = 1;
			}
			p=p->next;
		}
	}
}

int lienThongManh(){
	for(int i=1;i<=n;i++){
		BFS(i);
		int j;
		for( j=1;j<=n;j++){
			if(!daxet[i])	return 0;
		}
		if(j>n){
			for(int k=1;k<=n;k++)	daxet[k] = 0;
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
	
	if(lienThongManh())	cout<<"Do thi lien thong manh";
	else cout<<"Do thi lien thong yeu";
	
	return 0;
}
