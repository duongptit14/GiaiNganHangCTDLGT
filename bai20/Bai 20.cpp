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

void delete_childLeft(tree &root,int x){
	NODE *p = search(root,x);
	if(p == NULL)	return;
	if(p->left != NULL)	delete (p->left);
}

void delete_childRight(tree &root,int x){
	NODE *p = search(root,x);
	if(p == NULL)	return;
	if(p->right != NULL)	delete (p->right);
}

void xuatNLR(tree root){			// truoc
	if(root!=NULL){
		cout<<root->data<<" ";
		xuatNLR(root->left);
		xuatNLR(root->right);
	}
}
void xuatLNR(tree root){				//giua
	if(root!=NULL){
		xuatLNR(root->left);
		cout<<root->data<<" ";
		xuatLNR(root->right);
	}
}
void xuatLRN(tree root){				//sau
	if(root!=NULL){
		xuatLRN(root->left);
		xuatLRN(root->right);
		cout<<root->data<<" ";
	}
}


void xuatNLR_KhuDeQuy(tree root){		// truoc
	stack <tree> s;
	s.push(root);
	while(!s.empty()){
		NODE *p=s.top();
		cout<<p->data<<" ";
		s.pop();
		if(p->right!=NULL){
			s.push(p->right);
		}
		if(p->left!=NULL){
			s.push(p->left);
		}
	}	
}

void xuatLNR_KhuDeQuy(tree root){			// giua
	stack <tree> s;
	node *p=root;
	while(p!=NULL||!s.empty()){
		if(!p){
			p=s.top();
			s.pop();
			cout<<p->data;
			p=p->right;
		}else{
			s.push(p);
			p=p->left;
		}
	}
}

void xuatLRN_KhuDeQuy(tree root){	// sau
	stack<tree> s;
	node *p=root;
	while(p|| !s.empty()){
		if(!p){
			while(!s.empty() && p==s.top()->right){
				p=s.top();
				s.pop();
				cout<<p->data<<" ";
			}
			if(s.empty()){
				p=NULL;	
			}else{
				p=s.top()->right;
			}	
		}else{
			s.push(p);
			p=p->left;
		}
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
//	xuatLNR(root);
//	xuatLRN(root);


//	xuatNLR_KhuDeQuy(root);
//	xuatLNR_KhuDeQuy(root);
//	xuatLRN_KhuDeQuy(root);	
	return 0;
}
