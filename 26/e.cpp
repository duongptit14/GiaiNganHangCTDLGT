
/*copy*/

#include<iostream>
#include<stdlib.h>
#include<malloc.h>
using namespace std;

#define True 1
#define False 0
#define ORDER 4

struct node{
	int numtrees;		// so cay con cua 1 node
	int key[ORDER-1];	// cac khoa cua 1 node
	node *son[ORDER];	// cac con tro chi den node con cua 1 node cha
};
typedef struct node *tree_Node;
tree_Node ptree;

// khoi tao cay 
void Init(){
	ptree=NULL;
}

// khoi tao node moi
tree_Node GetNode(){
	tree_Node p;
	p= (tree_Node)malloc(sizeof(node));
	return p;
}

// huy mot node
void FreeNode(tree_Node p){
	free(p);
}

// Tao node moi co nhan k
tree_Node MakeNode(int k){
	int i;
	tree_Node p;
	p=GetNode();
	p->numtrees=2;
	p->key[0]=k;
	// khoi tao node moi chua co node con
	for(i=0;i<ORDER;i++)
		p->son[i]=NULL;
	return p;
}

// tim khoa k trong node p
// tra ve vi tri nho nhat cua cac khoa trong node p, thi tra ve vi tr p-<numtrees-1
int SearchNode(tree_Node p,int k){
	int i;
	for(i=0;i<p->numtrees-1 && p->key[i];i++)
		return i;
}

// tim khoa tren cay, neu co khoa k tai node p thi bien found = true
/* ham Search tra ve con tro chi node chua khoa k, bien position tra ve 
	vi tri cua khoa k co trong node p 
	Neu ko co khoa k tren cay, thi p=NULL va q(node cha cua p) chi node la co them khoa k vap
	bien found ve False
	ham Search tra ve q chi vi tri cua node la co the them khoa k
	bien position tra ve vi tri co the chen khoa k vao node la q*/

tree_Node Search(int k, int*pposition,int *pfound){
	int i;
	tree_Node p,q;
	q=NULL;
	p=ptree;
	while(p!=NULL){
		i=SearchNode(p,k);
		if(i<p->numtrees-1 && k==p->key[i]){	// found
			*pfound=True;
			*pposition=i;
			return p;
		}
		q=p;
		p=p->son[i];
	}
	*pfound=False;
	*pposition=i;
}

//   duyet cay
void Traverse(tree_Node proot){
	int i, nt;
	if(proot==NULL)
		return;
	else{
		nt=proot->numtrees;
		for(i=0;i<nt-1;i++){
			Traverse(proot->son[i]);
			cout<<"   "<<proot->key[i];
		}
		Traverse(proot->son[nt-1]);
	}
}

//  xem noi dung tung node tu tren xuong
void ViewNodes(tree_Node proot,int lever){
	int i;
	if(proot==NULL)	return;
	else{
		cout<<"\n Node "<<proot<<"(muc "<<lever<<")";
		for(i=0;i<proot->numtrees;i++){
			cout<<"  "<<proot->key[i];
		}
		cout<<endl;
		for(i=0;i<proot->numtrees;i++)
			ViewNodes(proot->son[i],lever+1);
	}
}

// chen 1 khoa vao node la
void InSleaf(tree_Node s,int k, int pos){
	int i, nt;
	nt=s->numtrees;
	s->numtrees=nt+1;
	for(i=nt-1;i>pos;i--){
		s->key[i]=s->key[i-1];
	}
	s->key[pos]=k;
}

// chen 1 khoa vao cay top-down
tree_Node Insert(int k){
	tree_Node s,p;
	int position, found;
	if(ptree=NULL){
		ptree= MakeNode(k);
		return ptree;
	}
	s=Search(k,&position,&found);
	if(found==True){
		cout<<" Khoa bi trung."<<endl;
		return s;
	}
	if(s->numtrees<ORDER){
		InSleaf(s,k,position);
		return s;
	}
	p=MakeNode(k);
	s->son[position]=p;
	return p;
}

int main(){
	int i,n,khoa,pos, timthay, function;
	tree_Node p;
	Init();
	do{
		system("cls");
		cout<<" *=============================================*"<<endl;
		cout<<"||        BINARY TREE TOP-DOWN                 ||"<<endl;
		cout<<"||                                             ||"<<endl;
		cout<<"||  1. Them mot khoa.                          ||"<<endl;
		cout<<"||  2. Duyet tu nho den lon.                   ||"<<endl;
		cout<<"||  3. Xem noi dung tung node cua cay Top-Down.||"<<endl;
		cout<<"||  4. Tim kiem khoa co nhan X.                ||"<<endl;
		cout<<"||  5. Thoat.                                  ||"<<endl;
		cout<<" *=============================================*"<<endl;
		cout<<" Moi nhap chuc nang: "; cin>>function;
		switch(function){
			case 1:
					cout<<" Nhap noi dung khoa moi muon them: "; cin>>khoa;
					Insert(khoa);
					break;
			case 2:
					cout<<" Duyet cay theo thu tu tu nho den lon."<<endl;
					if(ptree==NULL)
						cout<<" Cay bi rong."<<endl;
					else
						Traverse(ptree);
					break;
			case 3:
					cout<<" Xem noi dung tung node tu tren xuong."<<endl;
					if(!ptree)
						cout<<" Cay rong."<<endl;
					else{
						ViewNodes(ptree,0);
						system("pause");
					}
					break;
			case 4: 
					cout<<" Nhap khoa can tim: "; cin>>khoa;
					p=Search(khoa,&pos,&timthay);
					if(timthay)
						cout<<" Tim thay khoa "<<khoa<<" o vi tri "<<pos<<endl;
					else 
						cout<<" khong tim thay. "<<endl;						
		}
	}while(function!=5);
	return 1;
}

