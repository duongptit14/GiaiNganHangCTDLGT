#include<iostream>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
};
typedef struct node NODE;
typedef struct node *tree;
NODE *creatNode(int x){
	NODE *p=new NODE();
	p->data=x;
	p->left=p->right=NULL;
}
void creatTree(tree &root){
	root=NULL;
}
NODE *search(tree &root,int x){
	if(root==NULL)	return NULL;
	NODE *p=root;
	while(p!=NULL){
		if(p->data==x)	return p;
		if(x < p->data)	p=p->left;
		else p=p->right;	
	}
	return NULL;
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
		}else{
			if(f->right==NULL){
				f->right=p;
				return;
			}else f=f->right;
		}
	}	
}
void inItTree(tree &root,int a[],int n){
	for(int i=0;i<n;i++){
		insert(root,creatNode(a[i]));
	}
}


void xuatNLR(tree root){
	if(root!=NULL){
		cout<<root->data<<" ";
		xuatNLR(root->left);
		xuatNLR(root->right);
	}
}

void mirror(tree &root){
	if(root==NULL)	return;
	else{
		tree tmp;
		mirror(root->left);
		mirror(root->right);
		tmp=root->left;
		root->left=root->right;
		root->right=tmp;
	}
}

int main(){
	tree root;
	creatTree(root);
	int a[]={40,4,34,45,14,55,48,13,15,49,47};
	int n=11;
	inItTree(root,a,n);
	xuatNLR(root);
	cout<<"\n";
	mirror(root);
	xuatNLR(root);
	return 0;
}
