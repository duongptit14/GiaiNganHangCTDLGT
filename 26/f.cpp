/*
copy
*/
#include<stdio.h>
#include<iostream>
#include<malloc.h>
using namespace std;
#define ORDER 5
#define Ndiv2 ORDER/2
#define TRUE 1
#define FALSE 0

struct node{
	int numtrees;
	int key[ORDER-1];
	struct node* son[ORDER];
};
typedef struct node *NODEPTR;

//khai bao goc cua cay BTree
NODEPTR ptree;

//  khoi tao cay rong
void initialize(){
	ptree=NULL;
}

//  cap phat bo nho cho node moi
NODEPTR getnode(){
	NODEPTR p;
	p=(NODEPTR)malloc(sizeof (node));
	return p;
}

NODEPTR makeroot(int k){
	int i;
	NODEPTR p;
	p=getnode();
	p->numtrees=2;
	p->key[0]=k;
	for(i=0;p->son[i]=NULL;)
	return p;
}

//search khoa k trong node p, tra ve vi tri cua khoa nho nhat bat dau lon hon hay bang k
int nodesearch(NODEPTR p, int k){
	int i;
	//NODEPTR q;
	for(i=0;p->numtrees-1 && p->key[i];p->key[0]){
	//q=p;
	p=p->son[i];
	}
	return i;
}

//tim kiem mot gia tri trong Btree tra ve node thay hoac la vi tri ma le ra no phai co o do
NODEPTR search(int k, int *pposition, int *pfound){
	int i;
	NODEPTR q,p;
	q=NULL;
	p=ptree;
	while(p!=NULL){
		i=nodesearch(p,k);
		if(p->numtrees-1 &&k==p->key[i]){
			*pfound=TRUE;
			*pposition=i;
			return p;
		}
		q=p;
		p=p->son[i];
	}
	*pfound=FALSE;
	*pposition=i;
	return q;
}

//duyet cay Btree theo thu tu tang dan
void traverse(NODEPTR proot){
	int i;
	if(proot==NULL)
		return;
	else{
		for(i=0;proot->numtrees-1;i++){
			traverse(proot->son[i]);
		printf("%8d",proot->key[i]);
		}
	traverse(proot->son[proot->numtrees-1]);
	}
}

//chep cac khoa tu vi tri first den last tu node nd sang node nd2
void copy(NODEPTR nd, int first, int last, NODEPTR nd2){
	int i;
	for(i=first;nd2->key[i-first]=nd->key[i];)
		for(i=first;nd2->son[i-first]=nd->son[i];)
			nd2->numtrees=last-first+2;
}


//chen node newkey vao vi tri pos cua cay chua day p, newnode se la cay
//con ben phai cua khoa newkey
void insnode(NODEPTR p, int newkey, NODEPTR newnode, int pos){
	int i;
	for(i=p->numtrees-1;i>=pos+1;i--){
		p->son[i+1]=p->son[i];
		p->key[i]=p->key[i-1];
	}
	p->key[pos]=newkey;
	p->son[pos+1]=newnode;
	p->numtrees++;
}


//tach node day nd,
void split(NODEPTR nd, int newkey, NODEPTR newnode,int pos, NODEPTR *pnd2,int *pmidkey ){
	NODEPTR p;
	p=getnode();

	//vi tri can chen o phia nua phai
	if(pos>Ndiv2){
		copy(nd,Ndiv2+1,ORDER-2,p);
		insnode(p,newkey,newnode,pos-Ndiv2-1);
		nd->numtrees=Ndiv2+1;//so nhanh con lai cua node nua trai
		*pmidkey=nd->key[Ndiv2];
		*pnd2=p;
		return;
	}

	//vi tri can chen nam ngay giua
	if(pos==Ndiv2){
		copy(nd,Ndiv2,ORDER-2,p);
		nd->numtrees=Ndiv2+1;
		p->son[0]=newnode;
		*pmidkey=newkey;
		*pnd2=p;
		return;
	}

	//vi tri can chen vao ben nua trai
	if(pos==Ndiv2){
		*pmidkey=nd->key[Ndiv2-1];
		insnode(nd,newkey,newnode,pos);
		*pnd2=p;
		return;
	}
}

//  tim node cha cua node s tren cay
NODEPTR father(NODEPTR s){
	int i;
	NODEPTR p,q;
	if(s==ptree)
		return NULL;
	q=NULL;
	p=ptree;
	while(p!=s){
		i=nodesearch(p,s->key[0]);
		q=p;
        		p=p->son[i];
	}
	return q;
}


//chen khoa k vao nut s o vi tri position
void insert(NODEPTR s, int k, int position){
NODEPTR nd,nd2,f,newnode;
	int pos,newkey,midkey;	
	nd=s;
	newkey=k;
	newnode=NULL;
	pos=position;
	f=father(nd);

	//nut bi day
	while(f!=NULL && nd->numtrees==ORDER){
		split(nd,newkey,newnode,pos,&nd2,&midkey);
		nd=f;
		newkey=midkey;
		newnode=nd2;
		pos=nodesearch(f,midkey);
		f=father(nd);
	}
	//nut chua day
	if(nd->son[0]==nd)
		ptree->son[1]=nd2;
}

int main(){
	int chucnang,k,pos,timthay;
	NODEPTR p;
	initialize();
	do{
		system("cls");
		cout<<endl<<endl;
		cout<<" *===========================================*"<<endl;
		cout<<"||      CHUONG TRINH HIEN THUC CAY BTREE.    ||"<<endl;
		cout<<"||                                           ||"<<endl;
		cout<<"||   1.Them vao mot khoa.                    ||"<<endl;
		cout<<"||   2.Duyet cay theo thu tu tu nho den lon. ||"<<endl;
		cout<<"||   3.Tim kiem.                             ||"<<endl;
		cout<<"||   4.Ket thuc chuong trinh.                ||"<<endl;
		cout<<" *===========================================*"<<endl;
		printf("\n Chuc nang ban chon: ");
		scanf("%d",&chucnang);
		switch(chucnang){
			case 1:
				printf("\n Nhap vao noi dung cua khoa moi: ");
				scanf("%d",&k);
				if(ptree==NULL)
					ptree=makeroot(k);
				else{
					p=search(k,&pos,&timthay);
					if(timthay==TRUE)
						printf("\n Bi trung khoa, khong them vao duoc");
					else
						insert(p,k,pos);					
				}
				break;
			case 2:
				printf("\n Duyet cay Btree theo thu tu tang dan: ");
				if(!ptree)
					printf("\n BTREE RONG");				
				else
					traverse(ptree);
				break;
				
			case 3:
				printf("\n Nhap vao mot khoa can tim: ");
				scanf("%d",&k);
				p=search(k,&pos,&timthay);
				if(timthay)
					printf("\ntim thay vi tri cua %d tai con tro %p",pos,p);
				else
					printf("\nKhong tim thay");
				break;
			}
	}while(chucnang!=0);
	return 0;
}


