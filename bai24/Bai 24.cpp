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

void xoaNode(tree &root, int x){
	if(root==NULL)	return;
	if(root->data > x)	xoaNode(root->left,x);
	else if(root->data < x) xoaNode(root->right,x);
	else {
		NODE *p=root;
		if(p->left==NULL&&p->right!=NULL){
			root=root->right;
		}else if(p->left!=NULL&&p->right==NULL){
			root=root->left;
		}else{
			NODE *r=p->right;
			while(r->left!=NULL){
				r=r->left;
			}
			r->left=p->left;
		}
		delete (p);
	}
}

void inItTree(tree &root,int a[],int n){
	for(int i=0;i<n;i++){
		insert(root,creatNode(a[i]));
	}
}

void xoayPhai(tree &root){
	NODE *p=root->left;
	root->left=p->right;
	p->right=root;
	root=p;
}

void xoayTrai(tree &root){
	NODE *p=root->right;
	root->right=p->left;
	p->left=root;
	root=p;
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
	while(p!=NULL || !s.empty()){
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
	int a[]={40,4,34,45,14,55,48,13,15,49,47};
	int n=11;
	inItTree(root,a,n);
	//xuatNLR(root);
	xuatLNR(root);
//	xuatLRN(root);
//	cout<<"\n";
//	xoayPhai(root);
//	xoayTrai(root);
//	xuatNLR(root);
//	xuatNLR_KhuDeQuy(root);
//	xuatLRN_KhuDeQuy(root);	
	return 0;
}
