#include<iostream>
#include<stack>
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
NODE *search(tree root,int x){
	if(root==NULL)	return NULL;
	if(root->data == x)	return root;
	NODE *p=search(root->left,x);
	if(p == NULL)	p=search(root->right,x);
	
	return p;
}

void add_childRight(tree &root,int x,int value){
	NODE *p = search(root,x);
	if(p == NULL)	return;
	NODE *tmp = creatNode(value);
	p->right = tmp;
}

void add_childLeft(tree &root,int x,int value){
	NODE *p = search(root,x);
	if(p == NULL)	return;
	NODE *tmp = creatNode(value);
	p->left = tmp;
}


void xuatNLR(tree root){			// truoc
	if(root!=NULL){
		cout<<root->data<<" ";
		xuatNLR(root->left);
		xuatNLR(root->right);
	}
}

int main(){
	tree root;
	creatTree(root);
	int a[7]={40,4,34,45,14,55,48};
	NODE *x = creatNode(40);
	root = x;
	add_childLeft(root,40,3);
	add_childRight(root,3,34);
	add_childRight(root,40,45);
	add_childLeft(root,34,14);
	add_childRight(root,45,55);
	add_childLeft(root,55,48);
	
	
	xuatNLR(root);
	cout<<"\n";
	return 0;
}
