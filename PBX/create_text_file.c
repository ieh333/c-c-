#include <stdio.h>
#include "create_text_file.h"

void create_text_file(char *text_file, char *data_file)
{
     char buff[256];
     char *buffer=buff;
     FILE *infile;
     FILE *outfile;
     infile=fopen(data_file,"r");
     outfile=fopen(text_file,"w");
     fprintf(outfile,"Nomer ");
     fprintf(outfile,"Ime ");
     fprintf(outfile,"Familia ");
     fprintf(outfile,"Tsena_na_abonamenta ");
     fprintf(outfile,"Broi_vklucheni_minuti ");
     fprintf(outfile,"Tsena_na_impuls(minata) ");
     fprintf(outfile,"Stara_stoinost ");
     fprintf(outfile,"Nova_stoinost\n");
     do{
         buffer=fgets(buff,256,infile);
         if(buffer!=NULL)
         {
           fprintf(outfile,"%s",buff);
         }
       } while(buffer!=NULL);
     fclose(outfile);
     fclose(infile);
     exit(0);
}
