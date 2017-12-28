#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

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

int DUYET[100];
int vt = 1;
int daxet[100] = {0};
void DFS(int i){
	DUYET[vt] = i;
	daxet[i]=1;
	vt++;
	NODE *p = L[i].phead;
	while(p != NULL){
		if(!daxet[p->data]){
			daxet[p->data] = 1;
			DFS(p->data);
		}
		p=p->next;
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
	
	cout<<"DFS (2) : "<<endl;
	DFS(2);
	for(int i=1;i<vt;i++){
		cout<<DUYET[i]<<" ";
	}
	
	return 0;
}
