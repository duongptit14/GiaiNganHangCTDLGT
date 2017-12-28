#include<iostream>
#include<fstream>
#include<string.h>
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
		L.ptail->next=L.phead;
	}else{
		L.ptail->next=p;
		p->next=L.phead;
		L.ptail=p;
	}
}

void Action(list &L, string x){
	NODE *p=L.phead;
	if(p->data==x){
		p->sl++;
		return;
	}
//	p=p->next;
//	while(p!=L.phead){
//		if(p->data==x){
//		p->sl++;
//		return;
//		}
//		p=p->next;
//	}
//	add(L,x);
}

void read(list &L){
	fstream f;
	f.open("ds.in",ios::in);
	while(!f.eof()){
		string x;
		f>>x;
		if(!f.eof()){
			Action(L,x);
		}
	}
}
void xuat(list L){
	NODE *p=L.phead;
	cout<<p->data<<"\t"<<p->sl<<"\n";
	p=p->next;
	while(p!=L.phead){
		cout<<p->data<<"\t"<<p->sl<<"\n";
		p=p->next;
	}
}

int main(){
	list L;
	creatList(L);
	read(L);
	//xuat(L);
	return 0;
}
