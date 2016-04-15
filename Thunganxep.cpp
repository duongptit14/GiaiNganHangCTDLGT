#include<iostream>
#include<malloc.h>
#include<cstring>
using namespace std;
typedef struct node{
	char so;
	struct node *next;
}*Stack;
void init(Stack *plist)
{
	*plist=NULL;
}
Stack Getnode(void)
{
	Stack p;
	p=new(struct node);
	return p;
}
int Emptynode(Stack *plist)
{
	if(*plist==NULL)
	{
		return 1;
	}
	return 0;
}
void Freenode(Stack p)
{
	free(p);
}
void push(Stack *plist,char x)
{
	Stack p;
	p=Getnode();
	p->so=x;
	if(Emptynode(plist))
	{
		*plist=p;
		p->next=NULL;
			
	}
	else
	{
	p->next=*plist;
	*plist=p;
	}
}
char pop(Stack *plist)
{
	Stack p;
	char x[2];
	p=Getnode();
	p=*plist;
	if(Emptynode(plist))
	{
		return ' ';
	}
	*plist=p->next;
	x[1]=p->so;
	p->next=NULL;
	free(p);
	return x[1];
}
char Get(Stack *plist)
{
	Stack p;
	char x[2];
	p=Getnode();
	p=*plist;
	if(Emptynode(plist))
	{
		return ' ';
	}
	x[1]=p->so;
	return x[1];
}
void display(Stack *plist)
{
	Stack p;
	p=Getnode();
	p=*plist;
	while(p!=NULL)
	{
		cout<<p->so<<" ";
		p=p->next;
	}
	cout<<'\n';
}
int priority(char x)
{
	if(x=='+'||x=='-') return 1;
	if(x=='*'||x=='/') return 2;
}
int main(void)
{
	Stack p,q,r;
	init(&p);
	init(&q);
	char x[100];
	cin>>x;
	int n=strlen(x);
	char y;
	for(int i=0;i<n;i++)
	{
		if(x[i]=='(')
		{
			push(&p,x[i]);
		}
		else if(x[i]=='+'||x[i]=='-'||x[i]=='*'||x[i]=='/')
		{
			y=Get(&p);
			if(y==' ')
			{
				push(&p,x[i]);
			}
			else if(priority(x[i])>=priority(y))
			{
				push(&p,x[i]);
			}
			else if(priority(x[i])<priority(y))
			{
				y=pop(&p);
				push(&q,y);
				push(&p,x[i]);
			}
		}
		else if(x[i]==')')
		{
			 y= pop(&p);
			while(y!='(')
			{
				push(&q,y);
				y=pop(&p);
			}
		}
		else
		{
			push(&q,x[i]);
		}
	}
	while(p!=NULL)
	{
		y=pop(&p);
		push(&q,y);
	}
	display(&q);
	return 0;
}
