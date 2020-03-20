#include <stdio.h>
#include <string.h>
#include "countlines.h"
#include "total_minutes.h"

void total_minutes(char *text_file)
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
     int total_m=0;
     char *p_str;
     char substr[3];
     infile=fopen(text_file, "r");
     lines=countlines(text_file);
     fgets(str, 200, infile);
     printf("\n \n \n");
     printf("Molia, vavedete parvite dve tsifri na telefonnite nomera na abonatite:");
     scanf("%s", &substr);
     for(i=1;i<lines-1;i++)
     {
       fgets(str, 200, infile);
       sscanf(str, "%s %s %s %f %d %f %d %d", subscr.tel, subscr.fname, subscr.lname, &subscr.price, &subscr.minute, &subscr.m_price, &subscr.old_m, &subscr.new_m);
       diff_m=subscr.new_m-subscr.old_m;
       p_str=strstr(subscr.tel, substr);
       if(p_str!=NULL)
       {
         total_m+=diff_m;
       }
     }
     printf("Obshtia broi izgovoreni minuti ot abonatite s telefonni nomera, koito zapochat s tsifrite %s e %d minuti.", substr, total_m);
     free(str);
}
