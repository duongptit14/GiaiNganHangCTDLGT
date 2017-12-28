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

NODE *search(tree root, int x){
	
	if(root->data==x)	return root;
	if(root==NULL)	return NULL;
	int i=1;
	NODE *p=search(root->left,x);
	if(p==NULL)
	p=search(root->right,x);
	return p;
}

void add_Left(NODE *p1,node *p2){
	if(p1!=NULL && p1->left==NULL){
		p1->left=p2;
	}	
}
void add_Right(NODE *p1,NODE *p2){
	if(p1!=NULL && p1->right==NULL){
		p1->right=p2;
	}
}


void xuatNLR(tree root){
	if(root!=NULL){
		cout<<root->data<<" ";
		xuatNLR(root->left);
		xuatNLR(root->right);
	}
}

int isCayTong(tree root){
	if(root==NULL || root->left == NULL || root->right == NULL)	return 1;
	else{
		int l,r;
		if(root->left != NULL)	l = root->left->data;
		if(root->right != NULL)	r = root->right->data;
		if(root->data == l+r && isCayTong(root->left) && isCayTong(root->right))	return 1;
		else return 0; 
	}
}

int main(){
	tree root;
	creatTree(root);
	NODE *p=new NODE();
	p->data=10;
	p->left= p->right=NULL;
	root=p;
	add_Left(search(root,10),creatNode(8));
	add_Right(search(root,10),creatNode(2));
	add_Left(search(root,8),creatNode(5));
	add_Right(search(root,8),creatNode(3));
	xuatNLR(root);
	if(isCayTong(root))	cout<<"\nYes\n";
	else cout<<"\nNo\n";
	return 0;
}
