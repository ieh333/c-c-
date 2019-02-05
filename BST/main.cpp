#include <iostream>
#include <stdlib.h>

using namespace std;

//Structura na vazela na dvoichnoto darvo za tarsene
struct Node
{
    int data;
    Node *left;
    Node *right;
};

//Vasel na steka
struct sNode
{
    Node *t;
    sNode *next;
};

// Functsia za dobaviane na element 'k' kam steka
void push(sNode **s, Node *k)
{
    sNode *temp=(sNode *)malloc(sizeof(sNode));

    //Tuk se izpalniava proverka na pametta
    temp->t=k;
    temp->next=*s;
    (*s)=temp;
}

//Functsia za premahvane na element 't' ot steka
Node *pop(sNode **s)
{
    Node *t;
    sNode *st;
    st=*s;
    (*s)=(*s)->next;
    t=st->t;
    free(st);
    return t;
}

//Functsia, koiato proveriava dali steka e prazen ili ne
int isEmpty(sNode *s)
{
    if(s==NULL)
    {
        return 1;
    }
    return 0;
}

//Polezna funtsia za sazdavane na novo dvoichno darvo za tarsene
Node *newNode(int data)
{
    Node *temp=new Node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

//Polezna functsia za otpechatvane na podhodiashto podredeno dvoichno darvo
void inorder(Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

//Functsia za otpechatvane na dannite na dve dvoichni darveta za tarsene v podreden red
void merge(Node *root1, Node *root2)
{
    //s1 e stek, koito pritejava vazli na parvoto darvo
    sNode *s1=NULL;

    //Tekusht vazel na parvoto BST
    Node *current1=root1;

    //s2 e stek, koito pritejava vazli na vtoroto darvo
    sNode *s2=NULL;

    //Tekusht vazel na vtoroto BST
    Node *current2=root2;

    //Ako parvoto BST e prazno, togava na izhoda e vtoroto darvo, koeto e podhodiashto podredeno
    if(root1==NULL)
    {
        inorder(root2);
        return;
    }

    //Ako vtoroto BST e prazno, togava na izhoda e parvoto darvo, koeto e podhodiashto podredeno
    if(root2==NULL)
    {
        inorder(root1);
        return;
    }

    //Startira tsikal, dokato ima vazli, koito oshte ne sa otpechatani
    //Vazlite mogat da badat v steka (proucheni, no ne otpechatani)
    //ili moje vse oshte da ne badat proucheni
    while((current1!=NULL)||(!isEmpty(s1))||(current2!=NULL)||(!isEmpty(s2)))
    {
        //Sledvashtite stapki sledvat iterativno podhodiashto podrejdane
        if(current1!=NULL||current2!=NULL)
        {
            //Dostiga nai-leviat vazel na dvete darveta i vmakva predshestvanitsi na nai-levite vazli kam steka s1 i s2 saotvetno
            if(current1!=NULL)
            {
                push(&s1,current1);
                current1=current1->left;
            }
            if(current2!=NULL)
            {
                push(&s2,current2);
                current2=current2->left;
            }
        }
        else
        {
            //Ako dostignem NULL vazel i vseki ot stekovete sa prazni, togava edno darvo e izcherpano i se otpechatva drugoto
            if(isEmpty(s1))
            {
                while(!isEmpty(s2))
                {
                    current2=pop(&s2);
                    current2->left=NULL;
                    inorder(current2);
                }
                return;
            }
            if(isEmpty(s2))
            {
                while(!isEmpty(s1))
                {
                    current1=pop(&s1);
                    current1->left=NULL;
                    inorder(current1);
                }
                return;
            }

            //Premahva element ot dvata steka i sravniava vzetite elementi
            current1=pop(&s1);
            current2=pop(&s2);

            //Ako elementa na parvoto darvo e po-malko, togava go printira i vmakva nai-diasnoto poddarvo.
            //Ako elementa e po-goliamo, togava go vmakvame obratno kam saotvetnia stek.
            if(current1->data<current2->data)
            {
                cout<<current1->data<<" ";
                current1=current1->right;
                push(&s2,current2);
                current2=NULL;
            }
            else
            {
                cout<<current2->data<<" ";
                current2=current2->right;
                push(&s1,current1);
                current1=NULL;
            }
        }
    }
}



int main()
{
    Node *root1=NULL;
    Node *root2=NULL;

    //Parvoto BST
    root1=newNode(8);
    root1->left=newNode(2);
    root1->right=newNode(10);

    //Vtoroto BST
    root2=newNode(5);
    root2->left=newNode(3);
    root2->right=newNode(7);
    root2->right=newNode(9);


    merge(root1,root2);
    return 0;
}
