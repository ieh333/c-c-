#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef int bool;
#define true 1
#define false 0

//Polinom, koito se sahraniava pod formata na svarzan spisak
struct Polinoms
{
    int Factor;
    int Power;
    struct Polinoms *next;
};

struct Polinoms *p;

//Functsia za sazdavane na svarzan spisak
struct Polinoms* createList()
{
    struct Polinoms *head=NULL;
    head=malloc(sizeof(struct Polinoms));
    printf("Vavedete koefitsienta na elementa na polinoma:");
    scanf("%d",&(head->Factor));
    printf("Vavedete stepenta na elementa na polinoma:");
    scanf("%d",&(head->Power));
    head->next=NULL;
    return head;
}

//Functsia za otpechatvane na spisak
void printList(struct Polinoms *L)
{
    printf("{");
    while(L!=NULL)
    {
        printf("(%d,%d)",L->Factor,L->Power);
        L=L->next;
    }
    printf("}");
}

//Functsia za dobaviane na nov element kam kraia na spisaka
void append(struct Polinoms **L, int factor, int power)
{
    //
    struct Polinoms *new_node;
    struct Polinoms *last;
    new_node=(struct Polinoms *)malloc(sizeof(struct Polinoms));
    last=*L;
    //Vavejdane na dannite
    new_node->Factor=factor;
    new_node->Power=power;
    //Poslednia element shte bade poslednia, t.e. shte sochi kam NULL
    new_node->next=NULL;
    //Ako svarzania spisa e prazen, togava novia vazel shte bade nachalo
    if(*L==NULL)
    {
        *L=new_node;
        return;
    }
    //Inache preminavat do poslednia vazel
    while(last->next!=NULL)
    {
        last=last->next;
    }
    //Smeniava sledvashtia element ot poslenia vazel
    last->next=new_node;
    return;
}

//Functsia za izchisliavane na stoinostta na polinoma pri zadadeno realno chislo
double calculatePolinom(struct Polinoms *L, double x)
{
    double y;
    y=0;
    while(L!=NULL)
    {
        y+=L->Factor*pow(x,L->Power);
        L=L->next;
    }
    return y;
}

//Functsia za dobaviane na chlenove na polinoma s koefitsient 0, ako polinomat ne sadarja chlenove na vsichki stepeni na promenlivata
void insert_N_Position(int power, int n)
{
    int i;
    struct Polinoms *temp=(struct Polinoms*)malloc(sizeof(struct Polinoms*));
    temp->Factor=0;
    temp->Power=power;
    temp->next=NULL;
    if(n==1)
    {
        temp->next=p;
        p=temp;
        return;
    }
    struct Polinoms *temp2=p;
    for(i=0;i<n-2;i++)
    {
        temp2=temp2->next;
    }
    temp->next=temp2->next;
    temp2->next=temp;
    return;
}

//Functsia za dobaviane na chlenove v nachaloto na polinoma s koefitsient 0
void insert_Begin(int power)
{
    struct Polinoms *temp;
    temp=(struct Polinoms*)malloc(sizeof(struct Polinoms*));
    temp->Factor=0;
    temp->Power=power;
    temp->next=NULL;
    if(p!=NULL) temp->next=p;
    p=temp;
    return;
}

//Functsia za tarsene na opredelena stepen na polinoma v svarzania spisak
bool searchPower(struct Polinoms *L, int n)
{
    while(L!=NULL)
    {
        if(n==L->Power)
        {
            return true;
        }
        L=L->next;
    }
    return false;
}

int main()
{
    int f,pow,key;
    int number,power,pos,number2,power2;
    bool b;
    double x,y;
    p=createList();
    pow=p->Power;
    power=p->Power;
    while(pow!=0)
    {
        printf("Vavedete koefitsienta na elementa na polinoma:");
        scanf("%d",&f);
        printf("Vavedete stepenta na elementa na polinoma:");
        scanf("%d",&pow);
        append(&p,f,pow);
    }
    printf("\n");
    printf("Spisaka, koito predstavia polinoma s edna promenliva e:");
    printf("\n");
    printList(p);
    printf("\n");
    printf("\n");
    printf("MENU ZA IZBOR NA FUNCTSIA:\n");
    printf("1. - Izchisli stoinostta na polinoma.\n");
    printf("2. - Dobavi chlenove na polinoma s koefitsient 0, ako polinoma ne sadarja chlenove na vsichki stepeni na promenlivata.\n");
    printf("3. - Dobavi chlenove v nachaloto na polinoma s koefitsient 0.\n");
    printf("\n");
    scanf("%d",&key);
    switch(key)
    {
        case 1:
        printf("Vavedete edno realno chislo:");
        scanf("%lf",&x);
        y=calculatePolinom(p,x);
        printf("Stoinostta na polinoma pri zadadeno realno chislo e:");
        printf("\n");
        printf("%.2f",y);
        printf("\n");
        break;
        case 2:
        for(number=power;number>=0;number--)
        {
            pos=power-number+1;
            b=searchPower(p,number);
            if(b!=1)
            {
                insert_N_Position(number,pos);
            }
        }
        printList(p);
        break;
        case 3:
        printf("Vavedete stepenta 'power2' na polinoma, taka che 'power2 > power':");
        scanf("%d",&power2);
        for(number2=power;number2<=power2;number2++)
        {
            b=searchPower(p,number2);
            if(b!=1)
            {
                insert_Begin(number2);
            }
        }
        printList(p);
        break;
        default:
        printf("Vavedenata stoinost na 'key' e nepravilna.\n");
        break;
    }
    free(p);
    return 0;
}
