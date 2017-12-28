#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include<list>
using namespace std;

struct HashEntry{
   int key;
   list<string> list;
   HashEntry(int k)
   {        
         key=k;
   } 
}; 

class Hash{
  private:
         HashEntry *Table[100];
         int a;
  public:
         Hash(int A);
         void insert(string word);
         void Lookup(string word);
};    

Hash::Hash(int A)
{
    a=A;
}         

void Hash::insert(string word)
{
   int c=0;
   for (int i=0;i<word.size();i++)
   {                                 
       int b=(int)((a^i)*(word[i]));
       c+=b;
   }
   c%=100;
   list<string> list;
   if (Table[c-1]==NULL)     //if the respective bucket doesnot have any string
   Table[c-1]=new HashEntry(c-1);

   Table[c-1]->list.i(word);
}                  


void Hash::Lookup(string word)
{
   int c=0;
   for (int i=0;i<word.size();i++)
   {                                 
     int b=(int)((a^i)*(word[i]));
     c+=b;
   }
   cout<<"one"<<endl;
   c%=100;
   Table[c-1]->list.searchFor(word);
   cout<<"two"<<endl;
}
