#include "sub_menu.h"
#include "check_up.h"
#include "list_subscr.h"
#include "total_minutes.h"

void sub_menu()
{
     int number;
     char *file_text="pbx.txt";
     printf("1. Spravka za smetkata na vseki abonat\n");
     printf("2. Spisak na abonatite, neizrashodvali vkluchenite v abonamenta minuti\n");
     printf("3. Obsht broi izgovoreni minuti ot abonatite\n");
     printf("Vavedete nomera na optsiata v podmenuto:");
     while(scanf("%d",&number))
     {
       switch(number)
       {
         case 1:
              check_up(file_text);
              break;
         case 2:
              list_subscr(file_text);
              break;
         case 3:
              total_minutes(file_text);
              break;
         default:
                 printf("Vavedenia nomer e izvan intervala[1-3]!");
       }
     }
}
