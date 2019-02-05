//Programa za rabota s dvoichno darvo za pretarsvane
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

typedef int keyType;

struct BinOrdTree
{
   keyType key;
   BinOrdTree *left;
   BinOrdTree *right;
};

//Funktsia za vkluchvane na element v dvoichnoto darvo
void insertKey(keyType key, BinOrdTree **T)
{
   if(*T==NULL)
   {
      *T=(BinOrdTree *)malloc(sizeof(**T));
      (*T)->key=key;
      (*T)->left=NULL;
      (*T)->right=NULL;
   }
   else if(key<(*T)->key) insertKey(key, &(*T)->left);
   else if(key>(*T)->key) insertKey(key, &(*T)->right);
   else cerr<<"Elementat e veche v darvoto!\n";
}

//Funktsia za otpechatvane na nareden masiv, poluchen ot obhojdaneto na darvoto
void printTree(keyType out[], int index, BinOrdTree *T)
{
   int i=0;
   index=11;
   if(T==NULL) return;
   printTree(out,index,T->left);
   out[i]=T->key;
   cout<<out[i]<<" ";
   i++;
   printTree(out,index,T->right);
}

void main()
{
   clrscr();
   BinOrdTree *T, *result;
   const int index=11;
   keyType output[index];
   T=NULL;
   int input[]={6,-44,1,4,12,3,2,5,31,41,16};
   int i;
   int ikey;
   cout<<"Vavedete chislata:"<<endl;
   for(i=0;i<11;i++)
   {
      ikey=input[i];
      cout<<"Vmakva se element s kluch "<<ikey<<endl;
      insertKey(ikey, &T);
   }

   cout<<"Darvo: ";
   printTree(output,index,T);
}
