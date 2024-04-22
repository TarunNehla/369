// Q.7 Write a program to generate 3 address codes along with quadruples, triples, and indirect triples
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void pm();
void plus();
void divison();
int i, ch, j, l, addr = 100;
char exprsn[10], arr[10], arr1[10], arr2[10], id1[5], op[5], id2[5];
char temp_var = 'Z';
void main()
{
    while (1)
    {
        printf("\n1.assignment\n2.arithmetic\n3.relational\n4.Exit\nEnter the choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the arrression with assignment operator:");
            scanf("%s", arr);
            l = strlen(arr);
            arr2[0] = '\0';
            i = 0;
            while (arr[i] != '=')
            {
                i++;
            }
            strncat(arr2, arr, i);
            strrev(arr);
            arr1[0] = '\0';
            strncat(arr1, arr, l - (i + 1));
            strrev(arr1);
            printf("Three address code:\ntemp=%s\n%s=temp\n", arr1, arr2);
            break;

        case 2:

            printf("Enter the expression: ");
            scanf("%s", exprsn);

            printf("Intermediate code:\n");

            // The loop runs until the RHS of the expression is reduced to exactly one operand
            // e.g. a=U - strlen(exprsn) = 3
            while (strlen(exprsn) > 3)
            {
                // Un-comment the below statement to see how the original string is modified
                // printf("%s\n", exprsn);

                // flag is set to 1 when a subexpression is reduced
                int flag = 0;

                if (flag != 1)
                {
                    for (int i = 0; i < strlen(exprsn); i++)
                    {
                        // '/' and '*' given together for equal precedence
                        if (exprsn[i] == '/' || exprsn[i] == '*')
                        {
                            printf("%c=%c%c%c\n", temp_var, exprsn[i - 1], exprsn[i], exprsn[i + 1]);

                            // Substitute a new operand in the place of the subexpression
                            // e.g. - a=b+c*d-e -> a=b+Z*d-e
                            // (The final expression must be a=b+Z-e. The *d is removed in the below loop)
                            exprsn[i - 1] = temp_var;
                            temp_var--;

                            // Shift and replace with the characters to the right of the subexpression
                            for (int j = i; exprsn[j] != '\0'; j++)
                                exprsn[j] = exprsn[j + 2];

                            flag = 1;
                            break;
                        }
                    }
                }

                if (flag != 1)
                {
                    for (int i = 0; i < strlen(exprsn); i++)
                    {
                        // '+' and '-' given together for equal precedence
                        if (exprsn[i] == '+' || exprsn[i] == '-')
                        {
                            printf("%c=%c%c%c\n", temp_var, exprsn[i - 1], exprsn[i], exprsn[i + 1]);

                            exprsn[i - 1] = temp_var;
                            temp_var--;

                            for (int j = i; exprsn[j] != '\0'; j++)
                                exprsn[j] = exprsn[j + 2];

                            flag = 1;
                            break;
                        }
                    }
                }
            }

            printf("%s\n", exprsn);
            break;

        case 3:
            printf("Enter the arrression with relational operator");
            scanf("%s%s%s", &id1, &op, &id2);
            if (((strcmp(op, "<") == 0) || (strcmp(op, ">") == 0) || (strcmp(op, "<=") == 0) || (strcmp(op, ">=") == 0) || (strcmp(op, "==") == 0) || (strcmp(op, "!=") == 0)) == 0)
                printf("arrression is error");
            else
            {
                printf("\n%d\tif %s%s%s goto %d", addr, id1, op, id2, addr + 3);
                addr++;
                printf("\n%d\t T:=0", addr);
                addr++;
                printf("\n%d\t goto %d", addr, addr + 2);
                addr++;
                printf("\n%d\t T:=1", addr);
            }
            break;
        case 4:
            exit(0);
        }
    }
}
void pm()
{
    strrev(arr);
    j = l - i - 1;
    strncat(arr1, arr, j);
    strrev(arr1);
    printf("Three address code:\ntemp=%s\ntemp1=%c%ctemp\n", arr1, arr[j + 1], arr[j]);
}
void divison()
{
    strncat(arr1, arr, i + 2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n", arr1, arr[i + 2], arr[i + 3]);
}
void plus()
{
    strncat(arr1, arr, i + 2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n", arr1, arr[i + 2], arr[i + 3]);
}