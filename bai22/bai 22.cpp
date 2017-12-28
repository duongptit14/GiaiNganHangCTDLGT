#include <iostream>
#include <cmath> 
using namespace std;
 
struct  node{
    int key;
    int height;
    int size;
    node *left;
    node *right;
};
 
void swap(int *a, int *b)
{
    int t = *a; *a = *b; *b = t;
}
 
int max(int a, int b){
    return (a>b)?a:b;
}
 
node* createNode(int val)
{
    node *temp = new node();
    temp->key=val;
    temp->size=1;
    temp->height=0;
    temp->left=NULL;
    temp->right=NULL;
}
 
int Size(node *t)
{
    if(t==NULL)
        return 0;
    else
        return t->size;
}
 
int Height(node *t)
{
    if(t==NULL)
        return -1;
    else
        return t->height;
}
 
void updateHeightSize(node *t)
{
    t->height = max(Height(t->left),
                        Height(t->right))+1;
    t->size = Size(t->left) + Size(t->right)+1;
}
 
node* insert(node *n, int key)
{
    if(n==NULL){
        n = createNode(key);
        return n;
    }
    if(n->left==NULL ||
           Size(n->left)< int(pow(2, Height(n->left)+1))-1 ||
           Size(n->right)==Size(n->left)) 
           n->left = insert(n->left, key);
    else
        n->right = insert(n->right,key);
 
    if((n->left!=NULL && n->left->key < n->key) ||
            (n->right!=NULL && n->right->key < n->key)){
        if(n->left==NULL){
            swap(n->key, n->right->key);
        }
        else if(n->right==NULL)
            swap(n->key, n->left->key);
        else{
            if(n->left->key < n->right->key)
                swap(n->key, n->left->key);
            else
                swap(n->key, n->right->key);
        }
    }
    updateHeightSize(n);
    return n;
}
 
int top(node *root){
    return root->key;
}
 
node* remove(node *n, node *root)
{
    if(n==NULL)
        return NULL;
    if(n->left==NULL && n->right==NULL){
        swap(root->key, n->key);
        delete n;
        return NULL;
    }
    else if(Size(n->left) > Size(n->right))
        n->left = remove(n->left, root);
    else
        n->right = remove(n->right, root);
 
    updateHeightSize(n);
}
 
void search(node *n,int x){
	if(n==NULL)	return ;
	else if(n->key == x){
		cout<<"Size: "<<n->size<<"\tHeight: "<<n->height;
		return;
	}else{
		search(n->left,x);
		search(n->right,x);
	}
} 
 
void display(node *x){
	if(x!=NULL){
		cout<<x->key<<" ";
		display(x->left);
		display(x->right);
	}	
} 
 
int main()
{
    node *heap=NULL;
    int a[6]={12,7,6,10,8,20};
    for(int i=0;i<6;i++){
    	 heap = insert(heap, a[i]);
	}
    display(heap);
    cout<<"\n";
    search(heap,10);
    return 0;
}
