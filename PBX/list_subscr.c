#include <stdio.h>
#include "countlines.h"
#include "list_subscr.h"

void list_subscr(char *text_file)
{
     char *str;
     str=malloc(200);
     struct Subscription {
            char tel[10];
            char fname[20];
            char lname[30];
            float price;
            int minute;
            float m_price;
            int old_m;
            int new_m;
            };
    struct Subscription subscr;
    FILE *infile;
    int i, lines, diff_m;
    infile=fopen(text_file, "r");
    lines=countlines(text_file);
    fgets(str, 200, infile);
    printf("\n \n \n");
    printf("Abonatite, koito ne sa izrashodvali vkluchenite v abonamenta im minuti sa:\n");
    for(i=1;i<lines-1;i++)
    {
      fgets(str, 200, infile);
      sscanf(str, "%s %s %s %f %d %f %d %d", subscr.tel, subscr.fname, subscr.lname, &subscr.price, &subscr.minute, &subscr.m_price, &subscr.old_m, &subscr.new_m);
      diff_m=subscr.new_m-subscr.old_m;
      if(diff_m <= subscr.minute)
      {
       printf("%d. %s %s - %d minuti.\n",i, subscr.fname, subscr.lname, diff_m);
      }
    }
    free(str);
}
