#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;



struct donthuc{
	float hs;
	int sm;
};

typedef struct donthuc DT;

struct List{
	DT data;
	List *phead;
	List *ptail;
	List *next;
};

typedef struct List list; 

void xuat_DaThuc(list X);

void creatList(list &L){
	L.phead=L.ptail=NULL;
}

void add_DT(list &X,DT dt){
	List *p=new List();
	p->data=dt;
	p->next=NULL; 
	
	if(X.phead==NULL){
		X.phead=X.ptail=p;
	}else{
		X.ptail->next=p;
		X.ptail=p;
	}
}


void read_File(list &P, string filename){
	fstream f;
	f.open(filename,ios::in);
	while(!f.eof()){
		int x,y;
		f>>x>>y;
		DT dt;
		dt.hs=x;
		dt.sm=y;
		if(!f.eof()) add_DT(P,dt);
	}
}


list *tong_Hieu(list P,list Q,int nottong){
	list kq;
	creatList(kq);
	list *p=P.phead, *q=Q.phead;
	while(1){
		if(p->data.sm > q->data.sm){
			add_DT(kq,p->data);
			p=p->next;
		}else if(p->data.sm < q->data.sm){
			DT dt;
			dt.hs=q->data.hs*pow(-1,nottong);
			dt.sm=q->data.sm;
			add_DT(kq,dt);
			q=q->next;
		}else{
			DT dt;
			dt.hs=p->data.hs+ q->data.hs*pow(-1,nottong);
			dt.sm=q->data.sm;
			add_DT(kq,dt);
			p=p->next;
			q=q->next;
		}
		
		if(p==NULL){
			while(q!=NULL){
				DT dt;
				dt.hs=q->data.hs*pow(-1,nottong);
				dt.sm=q->data.sm;
				add_DT(kq,dt);
				q=q->next;
			}
			list *kq1=kq.phead;
			return kq1;
		}
		if(q==NULL){
			while(p!=NULL){
				add_DT(kq,p->data);
				p=p->next;
			}
			list *kq1=kq.phead;
			return kq1;
		}
	}
}


list *tich(list P,list Q){
	list kq;
	creatList(kq);
	list *p=P.phead, *q;
	while(p!=NULL){
		q=Q.phead;
		while(q!=NULL){
			DT dt;
			dt.hs=p->data.hs*q->data.hs;
			dt.sm=p->data.sm+q->data.sm;
			list *tmp=kq.phead;
			while(tmp!=NULL){
				if(dt.sm==tmp->data.sm){
					tmp->data.hs+=dt.hs;
					break;
				}
				tmp=tmp->next;
			}
			if(tmp==NULL){
				add_DT(kq,dt);
			}
			q=q->next;
		}
		p=p->next;
	}
	list *kq1=kq.phead;
	return kq1;
}

void daoham(list P){
	list kq;
	creatList(kq);
	list *p=P.phead; 
	while(p!=NULL){
		if(p->data.sm > 0){
			DT dt;
			dt.hs=p->data.hs*p->data.sm;
			dt.sm=p->data.sm-1;
			add_DT(kq,dt);
		}
		p=p->next;
	}
	xuat_DaThuc(kq);
}

void xuat_DaThuc(list X){
	list *p=X.phead;
	cout<<p->data.hs<<"x^"<<p->data.sm;
	p=p->next;
	while(p!=NULL){
		cout<<" +"<<p->data.hs<<"x^"<<p->data.sm;
		p=p->next;
	}
	cout<<"\n\n";
}

int main(){
	List P,Q;
	creatList(P);
	creatList(Q);
	string x="P.in";
	string y="Q.in";
	read_File(P,x);
	read_File(Q,y);
	
	xuat_DaThuc(P);
	xuat_DaThuc(Q);
	
//	list *tong=tong_Hieu(P,Q,1);
//	list TONG;	
//	TONG.phead=tong;
//	xuat_DaThuc(TONG);	
//	list *hieu=tong_Hieu(P,Q,0);
//	list HIEU;	
//	HIEU.phead=hieu;
//	xuat_DaThuc(HIEU);
//	
//	list *t=tich(P,Q);
//	list TICH;	
//	TICH.phead=t;
//	xuat_DaThuc(TICH);

	//daoham(P);
	return 0;
}
