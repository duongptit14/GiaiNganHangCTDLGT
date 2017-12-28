#include<iostream>
#include<fstream>
using namespace std;

struct node{
	string data;
	int sl;
	node *phead, *ptail, *next, *pre;
};

typedef struct node NODE;
typedef struct node list;

void creatList(list &L){
	L.phead=L.ptail=NULL;
}

void add(list &L,string x){
	NODE *q = new NODE();
	q->data = x;
	q->sl = 1;
	q->next = NULL;
	if(L.phead == NULL){
		L.phead = L.ptail = q;
		return;
	}
	NODE *p=L.phead;
	while(p->next!=NULL){
		if(p->next->data > x){
			q->next=p->next;
			p->next->pre=q;
			
			p->next=q;
			q->pre=p;
			return;
		}
		p=p->next;
	}
	p->next=q;
	q->pre=p;
	
	L.ptail=q;
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
	//for(int i=0;i<5;i++)	Action(L,a[i]);
	read(L);	
	xuat(L);
	return 0;
}
