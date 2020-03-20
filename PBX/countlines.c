#include <stdio.h>
#include "countlines.h"

int countlines(char *text_file)
{
    int ch,lines;
    FILE *infile;
    ch=0;
    lines=0;
    infile=fopen(text_file,"r");
    if(infile==NULL)
    {
       return 0;
    }
    lines++;
    while((ch=fgetc(infile))!=EOF)
    {
       if(ch=='\n')
       {
          lines++;
       }
    }
    fclose(infile);
    return lines;
}
