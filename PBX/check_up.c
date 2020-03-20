#include <stdio.h>
#include "countlines.h"
#include "check_up.h"

void check_up(char *text_file)
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
    float account, intermediate;
    infile=fopen(text_file, "r");
    lines=countlines(text_file);
    fgets(str, 200, infile);
    printf("\n \n \n");
    for(i=1;i<lines-1;i++)
    {
      fgets(str, 200, infile);
      sscanf(str, "%s %s %s %f %d %f %d %d", subscr.tel, subscr.fname, subscr.lname, &subscr.price, &subscr.minute, &subscr.m_price, &subscr.old_m, &subscr.new_m);
      diff_m=subscr.new_m-subscr.old_m;
      if(diff_m > subscr.minute)
      {
        intermediate=subscr.price+subscr.m_price*(diff_m-subscr.minute);
        account=intermediate+intermediate*0.2;
      }
      else
      {
          intermediate=subscr.price;
          account=intermediate+intermediate*0.2;
      }
      printf("Smetkata na %s %s e %.2f lv.\n", subscr.fname, subscr.lname, account);
    }
    free(str);
     
}
