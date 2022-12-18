#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "dec.h"


int check_dec(char * str)
{
    char * src1;
    char * src2;
    int f = 0;
    for (int i = 1; i < strlen(str); i++)
    {
        if ((str[i - 1] == ' ' || str[i - 1] == '+' || 
            str[i - 1] == '*' || str[i - 1] == '%' || str[i - 1] == '-' || 
            str[i - 1] == '&' || str[i - 1] == '|' || str[i - 1] == '^') &&
            (str[i] >=48 && str[i] <= 57))
        {
              
            if (strchr(str, ' ') != NULL)
            {
                src1 = (char *)calloc(i - 3, sizeof(char));
                strncpy(src1, str, i - 3);
            }
            else
            {
                src1 = (char *)calloc(i - 1, sizeof(char));
                strncpy(src1, str, i - 1);
            }
            
            src2 = (char *)calloc(strlen(str + i) + 1, sizeof(char));
            strcpy(src2, (str + i));
            
            for (int j = 0; j < strlen(src1); j++)
            {
                if (src1[j] < 48 || src1[j] > 57)
                {   
                    f = 1;
                    break;
                }
            }
            for (int j = 0; j < strlen(src2); j++)
            {
                if (src2[j] < 48 || src2[j] > 57)
                {   
                    f = 1;
                    break;
                }
            }
            free(src1);
            free(src2);
            if (f == 1)
                return -1; //плохие цифры
            return i; // все хорошo

        }
    } 
    return -1;

}


float do_dec_dec(char * str)
{
    char ch;
    int a;
    float result = 0.;
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        ch = str[i + 1];
        str[i + 1] = 'a';
        a = atoi(&str[i]);
        str[i + 1] = ch;
        if (a != 0)
        {
            result += pow(10, strlen(str) - 1 - i) * a;
        } 
        
    }
    a = atoi(&str[strlen(str) - 1]);
    if (a != 0)
    {
            result += a;
    }
    return result;
}

