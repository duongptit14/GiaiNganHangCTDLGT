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
	if(L.phead==NULL){
		L.phead=L.ptail=p;
		L.ptail->next = L.phead;
	}else{
		p->next=L.phead;
		L.ptail->next=p;
		L.ptail=p;	
	}
}

void Action(list &L, string x){
	NODE *p=L.phead;
	if(p==NULL){
		add(L,x);	return;
	}
	if(p->data == x){
		p->sl++;
		return;
	}
	NODE *r=p->next;
	while(r!=p){
		if(r->data == x){
			r->sl++;
			return;
		}
		r=r->next;
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
	cout<<p->data<<"\tsl: "<<p->sl<<"\n";
	NODE *r=p->next;
	while(r!=p){
		cout<<r->data<<"\tsl: "<<r->sl<<"\n";
		r=r->next;
	}
}

int main(){
	list L;
	creatList(L);
	read(L);
	xuat(L);
	return 0;
}
