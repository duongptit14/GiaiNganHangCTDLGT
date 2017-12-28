#include<iostream>
#include<fstream>
using namespace std;

struct node{
	string data;
	int sl;
	node *phead, *ptail, *next;
};

typedef struct node NODE;
typedef struct node list;

void creatList(list &L){
	L.phead=L.ptail=NULL;
}

void add(list &L,string x){
	NODE *p=new NODE();
	p->data=x;
	p->sl=1;
	p->next=NULL;
	if(L.phead==NULL){
		L.phead=L.ptail=p;
	}else{
		L.ptail->next=p;
		L.ptail=p;
		
	}
}

void Action(list &L, string x){
	NODE *p=L.phead;
	while(p!=NULL){
		if(p->data==x){
			p->sl++;
			return;
		}
		p=p->next;
	}
	add(L,x);
}

void read(list &L){
	fstream f;
	f.open("ds.in",ios::in);
	while(!f.eof()){
		string s;
		f>>s;
		if(!f.eof()){
			Action(L,s);
		}
	}
}

void xuat(list L){
	NODE *p=L.phead;
	while(p!=NULL){
		cout<<p->data<<"\tsl: "<<p->sl<<"\n";
		p=p->next;
	}
}

int main(){
	list L;
	creatList(L);
	read(L);
	
	xuat(L);
	return 0;
}
