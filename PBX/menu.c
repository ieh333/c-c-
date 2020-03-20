#include "menu.h"

void menu()
{
     int number;
     char *file_data="pbx.dat";
     char *file_text="pbx.txt";
     printf("1. Sazdavane na nov fail s danni\n");
     printf("2. Sazdavane na tekstov fail\n");
     printf("3. Dobaviane na novi zapisi v aktivnia fail\n");
     printf("4. Sazdavane na spravki\n");
     printf("Vavedete nomera na optsiata v menuto:");
     while(scanf("%d",&number))
     {
       switch(number)
       {
         case 1:
              create_data_file(file_data);
              break;
         case 2:
              create_text_file(file_text,file_data);
              break;
         case 3:
              append_text_file(file_text);
              break;
         case 4:
              printf("\n");
              sub_menu();
              break;
         default:
                 printf("Vavedenia nomer e izvan intervala[1-4]!");
       }
     }
}
