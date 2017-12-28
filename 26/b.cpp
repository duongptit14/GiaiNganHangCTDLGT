#include <iostream>
#include<string.h>
using namespace std;
struct tree{//Moi phan tu cua cay la mot ky tu
    char data;
    tree *l, *r;
}*root = NULL, *p = NULL, *t = NULL, *y = NULL;

struct node {
       struct tree *pt;
       struct node *next;
}*top = NULL, *q = NULL, *np = NULL;

void push(tree *ptr){
    np = new node;
    np->pt = ptr;
    np->next = NULL;
    if (top == NULL){
        top = np;
    }
    else{
        q = top;
        top = np;
        np->next = q;
    }
}
tree *pop(){
    if (top == NULL)	cout<<"tran bo nho\n";
    else{
        q = top;
        top = top->next;
        return(q->pt);
        delete(q);
    }
}
void oprnd_str(char val){
    if (val >= 48 && val <= 57){
        t = new tree;
        t->data = val;
        t->l = NULL;
        t->r = NULL;
        push(t);
    }
    else if (val >= 42 && val <= 47){
        p = new tree;
        p->data = val;
        p->l = pop();
        p->r = pop();
        push(p);
    }
}
char postorder(tree *w){
    if (w != NULL)
    {
        pstorder(w->l);
        pstorder(w->r);
        cout<<w->data;
    }
}
int main()
{
    char a[15];
    int i;
    int j = -1;
    cout<<"nhap chuoi ki tu\n"; cin>>a;
    i = strlen(a);
    while (i >= 0)
    {
        i--;
        oprnd_str(a[i]);
    }
    postorder(pop());    
    system("pause");
}
