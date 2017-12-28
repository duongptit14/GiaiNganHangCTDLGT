#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
struct node{
	string data;
	int sl;
	node *left;
	node *right;
};
typedef struct node NODE;
typedef struct node *tree;
NODE *creatNode(string x){
	NODE *p=new NODE();
	p->data=x;
	p->sl=1;
	p->left=p->right=NULL;
}
void creatTree(tree &root){
	root=NULL;
}
void insert(tree &root,NODE *p){
	if(root==NULL){
		root=p;
		return ;
	}
	NODE *f=root;
	while(f!=NULL){
		if(f->data > p->data){
			if(f->left==NULL){
				f->left=p;
				return ;
			}else f=f->left;
		}else if(f->data < p->data){
			if(f->right==NULL){
				f->right=p;
				return;
			}else f=f->right;
		}else if(f->data == p->data){
			f->sl++;
			break;
		}
	}	
}

void read(tree &root){
	fstream f;
	f.open("ds.in",ios::in);
		while(!f.eof()){
		string x;
		f>>x;
		if(!f.eof()){
			insert(root,creatNode(x));
		}
	}
}

void xuatNLR(tree root){
	if(root!=NULL){
		cout<<root->data<<"\tsl: "<<root->sl<<"\n";
		xuatNLR(root->left);
		xuatNLR(root->right);
	}
}


int main(){
	tree root;
	creatTree(root);
	read(root);
	xuatNLR(root);
	return 0;
}
