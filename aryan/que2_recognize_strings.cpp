#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//program to recognize strings under ‘a’, ‘a*b+’, ‘abb’
int main() {
   char s[20], c;
   int state = 0, i = 0;


   printf("Enter a string: ");
   fgets(s, sizeof(s), stdin);


   while (s[i] != '\0' && s[i] != '\n') {
       c = s[i++];
       switch (state) {
           case 0:
               if (c == 'a')
                   state = 1;
               else if (c == 'b')
                   state = 2;
               else
                   state = 6;
               break;
           case 1:
               if (c == 'a')
                   state = 3;
               else if (c == 'b')
                   state = 4;
               else
                   state = 6;
               break;
           case 2:
               if (c == 'a')
                   state = 6;
               else if (c == 'b')
                   state = 2;
               else
                   state = 6;
               break;
           case 3:
               if (c == 'a')
                   state = 3;
               else if (c == 'b')
                   state = 2;
               else
                   state = 6;
               break;
           case 4:
               if (c == 'a')
                   state = 6;
               else if (c == 'b')
                   state = 5;
               else
                   state = 6;
               break;
           case 5:
               if (c == 'a')
                   state = 6;
               else if (c == 'b')
                   state = 2;
               else
                   state = 6;
               break;
           case 6:
               printf("%s is not recognized.\n", s);
               exit(0);
       }
   }


   if (state == 1)
       printf("%s is accepted under rule 'a'\n", s);
   else if (state == 2 || state == 4)
       printf("%s is accepted under rule 'a*b+'\n", s);
   else if (state == 5)
       printf("%s is accepted under rule 'abb'\n", s);


   return 0;
}
