#include <stdio.h>
#include "append_text_file.h"

void append_text_file(char *text_file)
{
     unsigned short cont=1;
     int free_minutes, old_minutes, new_minutes;
     float subscription_price, minute_price;
     char number[10], fname[20], lname[30];
     char *tel_number=number;
     char *subscription_fname=fname;
     char *subscription_lname=lname;
     FILE *outfile;
     outfile=fopen(text_file,"a");
     while(cont==1)
     { 
       getchar();
       printf("Vavedete telefonnia nomer na abonata:");
       gets(tel_number);
       printf("Vavedete parvoto ime na abonata:");
       gets(subscription_fname);
       printf("Vavedete familiata na abonata:");
       gets(subscription_lname);
       printf("Vavedete tsena na abonamenta v lv.:");
       scanf("%f",&subscription_price);
       printf("Vavedete broia na vkluchenite minuti:");
       scanf("%d",&free_minutes);
       printf("Vavedete tsenata na edin impuls(edna minuta):");
       scanf("%f",&minute_price);
       printf("Vavedete staroto pokazanie na minutite:");
       scanf("%d",&old_minutes);
       printf("Vavedete novoto pokazanie na minutite:");
       scanf("%d",&new_minutes);
       fprintf(outfile,"%s ",tel_number);
       fprintf(outfile,"%s ",subscription_fname);
       fprintf(outfile,"%s ",subscription_lname);
       fprintf(outfile,"%.2f ",subscription_price);
       fprintf(outfile,"%d ",free_minutes);
       fprintf(outfile,"%.2f ",minute_price);
       fprintf(outfile,"%d ",old_minutes);
       fprintf(outfile,"%d\n",new_minutes);
       printf("\n");
       printf("\n");
       printf("\n");
       printf("Za da prodaljite. vavedete edna ot slednite stoinosti.\n");
       printf("1 - da\n");
       printf("0 - ne\n");
       printf("Iskate li da prodaljite da vavejdate novi abonati:");
       scanf("%u",&cont);
     }
     fclose(outfile);
     exit(0);
}
