#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "oct.h"


int check_oct(char * str)
{
    char * src1;
    char * src2;
    int f = 0;
    for (int i = 1; i < strlen(str); i++)
    {
        if (str[i] == '0' && (str[i - 1] == ' ' || str[i - 1] == '+' || 
            str[i - 1] == '*' || str[i - 1] == '%' || str[i - 1] == '-' || 
            str[i - 1] == '&' || str[i - 1] == '|' || str[i - 1] == '^'))
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
            
            for (int j = 1; j < strlen(src1); j++)
            {
                if (src1[j] < 48 || src1[j] > 55)
                {   
                    f = 1;
                    break;
                }
            }
            for (int j = 1; j < strlen(src2); j++)
            {
                if (src2[j] < 48 || src2[j] > 55)
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


float do_dec_oct(char * str)
{
    char ch;
    int a;
    float result = 0.;
    strcpy(str, str + 1);
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        ch = str[i + 1];
        str[i + 1] = 'a';
        a = atoi(&str[i]);
        str[i + 1] = ch;
        if (a != 0)
        {
            result += pow(8, strlen(str) - 1 - i) * a;
        } 
        
    }
    a = atoi(&str[strlen(str) - 1]);
    if (a != 0)
    {
            result += a;
    }
    return result;
}


char * do_oct(int a)
{
    char t_char;
    char * n_str = (char *)calloc(1, sizeof(char));
    n_str[0] = '0';
    char * tmp;
    int c = 0;
    int flag = 0;
    if (a < 0)
    {
        a = a * -1;
        flag = 1;
    }
    while (a > 0)
    {
        printf("%s\n", n_str);
        tmp = (char*)realloc(n_str, sizeof(char) * (c + 1));
        if (tmp == NULL)
        {
            printf("Ошибка выделения памяти\n");
            return NULL;
        }
        n_str = tmp;
        n_str[c] = (char)(a % 8 + 48); 
        c++;
        a = a / 8;
    }
    for (int i = 0; i < strlen(n_str) / 2; i++)
    {
        t_char = n_str[i];
        n_str[i] = n_str[strlen(n_str) - i - 1];
        n_str[strlen(n_str) - i - 1] = t_char;
    }
    if (flag == 1)
    {
        a = a * -1;
        tmp = (char*)realloc(n_str, sizeof(char) * (c + 1));
        if (tmp == NULL)
        {
            printf("Ошибка выделения памяти\n");
            return NULL;
        }
        n_str = tmp;
        for (int i = strlen(n_str); i > 0; i--)
        {
            n_str[i] = n_str[i - 1];
        }
        n_str[0] = '-';
    }

    return n_str;

}
