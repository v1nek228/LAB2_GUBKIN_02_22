#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "hex.h"
#include "oct.h"
#include "bin.h"
#include "dec.h"
#include <ctype.h>

int main()
{
    char * str = NULL;
    size_t size = 0;
    getline(&str, &size, stdin);
    str = strtok(str, "\n");
    if (str[0] == '0' && str[1] == 'x')
    {
        char * src3;
        char * src1;
        char * src2;
        if (strstr(str + 2, "0x") == NULL)
        {
            printf("ошибка: системы счисления не совпадают\n");
            return -1;
        }
        int i = check_hex(str);
        printf("%s\n", str);
        if (i == -1)
        {
            printf("ошибка: недопустимые символы\n");
            return -1;
        }
        int a = 10;
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
        
        if (strchr(str, ' ') != NULL && str[strchr(str, ' ') - str + 2] == ' ')
        {
            switch(str[i - 2])
            {
                case '+':
                    a = do_dec_hex(src1) + do_dec_hex(src2);
                    break;
                case '-':
                    a = do_dec_hex(src1) - do_dec_hex(src2);
                    break;
                case '*':
                    a = do_dec_hex(src1) * do_dec_hex(src2);
                    break;
                case '%':
                    a = (int)do_dec_hex(src1) % (int)do_dec_hex(src2);
                    break;
                case '&':
                    a = (int)do_dec_hex(src1) & (int)do_dec_hex(src2);
                    break;
                case '|':
                    a = (int)do_dec_hex(src1) | (int)do_dec_hex(src2);
                    break;
                case '^':
                    a = (int)do_dec_hex(src1) ^ (int)do_dec_hex(src2);
                    break;
                default:
                    printf("операция не определена\n");
                    return -1;
            }
        }

        else if (strchr(str, ' ') == NULL)
        {
            switch(str[i - 1])
            {
                case '+':
                    a = do_dec_hex(src1) + do_dec_hex(src2);
                    break;
                case '-':
                    a = do_dec_hex(src1) - do_dec_hex(src2);
                    break;
                case '*':
                    a = do_dec_hex(src1) * do_dec_hex(src2);
                    break;
                case '%':
                    a = (int)do_dec_hex(src1) % (int)do_dec_hex(src2);
                    break;
                case '&':
                    a = (int)do_dec_hex(src1) & (int)do_dec_hex(src2);
                    break;
                case '|':
                    a = (int)do_dec_hex(src1) | (int)do_dec_hex(src2);
                    break;
                case '^':
                    a = (int)do_dec_hex(src1) ^ (int)do_dec_hex(src2);
                    break;
                default:
                    printf("операция не определена\n");
                    return -1;
            }
        }
        else
        {
            printf("некорректный ввод (несимметричный)\n");
            return -1;
        }
        free(src1);
        free(src2);
        src3 = do_hex(a);
        printf("0x%s (%d)\n", src3, a);
        free(src3);
        return 0;
    }
    if (str[0] == '0')
    {
        char * src3;
        char * src1;
        char * src2;
        int a = 10;
        if (strstr(str + 1, " 0") == NULL && strstr(str + 1, "+0") == NULL &&
            strstr(str + 1, "*0") == NULL && strstr(str + 1, "%0") == NULL && 
            strstr(str + 1, "&0") == NULL && strstr(str + 1, "|0") == NULL &&
            strstr(str + 1, "-0") == NULL && strstr(str + 1, "^0") == NULL)
        {
            printf("ошибка: системы счисления не совпадают\n");
            return -1;
        }
        int i = check_oct(str);   
        if (i == -1)
        {
            printf("ошибка: недопустимые символы\n");
            return -1;
        }

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

        if (strchr(str, ' ') != NULL && str[strchr(str, ' ') - str + 2] == ' ')
        {
            switch(str[i - 2])
            {
                case '+':
                    a = do_dec_oct(src1) + do_dec_oct(src2);
                    break;
                case '-':
                    a = do_dec_oct(src1) - do_dec_oct(src2);
                    break;
                case '*':
                    a = do_dec_oct(src1) * do_dec_oct(src2);
                    break;
                case '%':
                    a = (int)do_dec_oct(src1) % (int)do_dec_oct(src2);
                    break;
                case '&':
                    a = (int)do_dec_oct(src1) & (int)do_dec_oct(src2);
                    break;
                case '|':
                    a = (int)do_dec_oct(src1) | (int)do_dec_oct(src2);
                    break;
                case '^':
                    a = (int)do_dec_oct(src1) ^ (int)do_dec_oct(src2);
                    break;
                default:
                    printf("операция не определена\n");
                    return -1;
            }
        }

        else if (strchr(str, ' ') == NULL)
        {
            switch(str[i - 1])
            {
                case '+':
                    a = do_dec_oct(src1) + do_dec_oct(src2);
                    break;
                case '-':
                    a = do_dec_oct(src1) - do_dec_oct(src2);
                    break;
                case '*':
                    a = do_dec_oct(src1) * do_dec_oct(src2);
                    break;
                case '%':
                    a = (int)do_dec_oct(src1) % (int)do_dec_oct(src2);
                    break;
                case '&':
                    a = (int)do_dec_oct(src1) & (int)do_dec_oct(src2);
                    break;
                case '|':
                    a = (int)do_dec_oct(src1) | (int)do_dec_oct(src2);
                    break;
                case '^':
                    a = (int)do_dec_oct(src1) ^ (int)do_dec_oct(src2);
                    break;
                default:
                    printf("операция не определена\n");
                    return -1;
            }
        }
        else
        {
            printf("некорректный ввод (несимметричный)\n");
            return -1;
        }
        free(src1);
        free(src2);
        src3 = do_oct(a);
        printf("0%s (%d)\n", src3, a);
        free(src3);
        return 0;
    }
    if (str[0] == '~')
    {   
        int f = 0;
        char * src3;
        int a = 10;
        if (str[1] == '0' && str[2] == 'x')
        {
            for (int i = 3; i < strlen(str); i++)
            {
                if ((str[i] < 48 || str[i] > 57) && (tolower(str[i]) < 97 || tolower(str[i]) > 102))
                {
                    f = 1;
                    break;
                }
            }
            if (f == 0)
            {
                strcpy(str, str + 1);
                a = do_dec_hex(str);
                a = ~a;
                src3 = do_hex(a);
                printf("0x%s (%d)\n", src3, a);
                free(src3);
                return 0;
            }
            return 0;
        }
        else if (str[1] == '0')
        {
            for (int i = 2; i < strlen(str); i++)
            {
                if (str[i] < 47 && str[i] > 55)
                {
                    f = 1;
                    break;
                }
            }
            if (f == 0)
            {
                strcpy(str, str + 1);
                a = do_dec_oct(str);
                a = ~a;
                src3 = do_oct(a);
                printf("0%s (%d)\n", src3, a);
                free(src3);
                return 0;
            }
            return 0;
        }
        for (int i = 1; i < strlen(str); i++)
        {
            if (str[i] != '0' && str[i] != '1')
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            strcpy(str, str + 1);
            a = do_dec_bin(str);
            a = ~a;
            src3 = do_bin(a);
            printf("%s (%d)\n", src3, a);
            free(src3);
            return 0;
        }
        f = 0;
        for (int i = 1; i < strlen(str); i++)
        {
            if (str[i] < 48 || str[i] > 57)
            {
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            strcpy(str, str + 1);
            a = do_dec_dec(str);
            a = ~a;
            printf("%d\n", a);
            return 0;
        }
        return 0;
            
    }
    

    int fl = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != '0' && str[i] != ' ' && str[i] != '+' && 
            str[i] != '*' && str[i] != '%' && str[i] != '-' && 
            str[i] != '&' && str[i] != '|' && str[i] != '^' &&
            str[i] != '1')
        {
            fl = 1;
            break;
        }
            
    }
    if (fl == 0)
    {
        char * src3;
        char * src1;
        char * src2;
        int a = 10;
        if (strstr(str + 1, " 1") == NULL && strstr(str + 1, "+1") == NULL &&
            strstr(str + 1, "*1") == NULL && strstr(str + 1, "%1") == NULL && 
            strstr(str + 1, "&1") == NULL && strstr(str + 1, "|1") == NULL &&
            strstr(str + 1, "-1") == NULL && strstr(str + 1, "^1") == NULL)
        {
            printf("ошибка: системы счисления не совпадают\n");
            return -1;
        }
        int i = check_bin(str);   
        if (i == -1)
        {
            printf("ошибка: недопустимые символы\n");
            return -1;
        }

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

        if (strchr(str, ' ') != NULL && str[strchr(str, ' ') - str + 2] == ' ')
        {
            switch(str[i - 2])
            {
                case '+':
                    a = do_dec_bin(src1) + do_dec_bin(src2);
                    break;
                case '-':
                    a = do_dec_bin(src1) - do_dec_bin(src2);
                    break;
                case '*':
                    a = do_dec_bin(src1) * do_dec_bin(src2);
                    break;
                case '%':
                    a = (int)do_dec_bin(src1) % (int)do_dec_bin(src2);
                    break;
                case '&':
                    a = (int)do_dec_bin(src1) & (int)do_dec_bin(src2);
                    break;
                case '|':
                    a = (int)do_dec_bin(src1) | (int)do_dec_bin(src2);
                    break;
                case '^':
                    a = (int)do_dec_bin(src1) ^ (int)do_dec_bin(src2);
                    break;
                default:
                    printf("операция не определена\n");
                    return -1;
            }
        }

        else if (strchr(str, ' ') == NULL)
        {
            switch(str[i - 1])
            {
                case '+':
                    a = do_dec_bin(src1) + do_dec_bin(src2);
                    break;
                case '-':
                    a = do_dec_bin(src1) - do_dec_bin(src2);
                    break;
                case '*':
                    a = do_dec_bin(src1) * do_dec_bin(src2);
                    break;
                case '%':
                    a = (int)do_dec_bin(src1) % (int)do_dec_bin(src2);
                    break;
                case '&':
                    a = (int)do_dec_bin(src1) & (int)do_dec_bin(src2);
                    break;
                case '|':
                    a = (int)do_dec_bin(src1) | (int)do_dec_bin(src2);
                    break;
                case '^':
                    a = (int)do_dec_bin(src1) ^ (int)do_dec_bin(src2);
                    break;
                default:
                    printf("операция не определена\n");
                    return -1;
            }
        }
        else
        {
            printf("некорректный ввод (несимметричный)\n");
            return -1;
        }
        free(src1);
        free(src2);
        src3 = do_bin(a);
        printf("%s (%d)\n", src3, a);
        free(src3);
        return 0;
    }
    
    char * src3;
    char * src1;
    char * src2;
    int a = 10;
    
    for (int i = 1; i < strlen(str); i++)
    { 
        if ((str[i] == '+' || str[i] == '*' || str[i] == '%' || str[i] == '-' || 
            str[i] == '&' || str[i] == '|' || str[i] == '^') &&
            (str[i + 1] == ' ' ? str[i + 2] < 49 || str[i + 2] > 57 : str[i + 1] < 49 || str[i + 1] > 57))
        {
            printf("ошибка: системы счисления не совпадают\n");
            return -1;
        }
    }        

    int i = check_dec(str);   
    if (i == -1)
    {
        printf("ошибка: недопустимые символы\n");
        return -1;
    }

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

    if (strchr(str, ' ') != NULL && str[strchr(str, ' ') - str + 2] == ' ')
    {
        switch(str[i - 2])
        {
            case '+':
                a = do_dec_dec(src1) + do_dec_dec(src2);
                break;
            case '-':
                a = do_dec_dec(src1) - do_dec_dec(src2);
                break;
            case '*':
                a = do_dec_dec(src1) * do_dec_dec(src2);
                break;
            case '%':
                a = (int)do_dec_dec(src1) % (int)do_dec_dec(src2);
                break;
            case '&':
                a = (int)do_dec_dec(src1) & (int)do_dec_dec(src2);
                break;
            case '|':
                a = (int)do_dec_dec(src1) | (int)do_dec_dec(src2);
                break;
            case '^':
                a = (int)do_dec_dec(src1) ^ (int)do_dec_dec(src2);
                break;
            default:
                printf("операция не определена\n");
                return -1;
        }
    }

    else if (strchr(str, ' ') == NULL)
    {
        switch(str[i - 1])
        {
            case '+':
                a = do_dec_dec(src1) + do_dec_dec(src2);
                break;
            case '-':
                a = do_dec_dec(src1) - do_dec_dec(src2);
                break;
            case '*':
                a = do_dec_dec(src1) * do_dec_dec(src2);
                break;
            case '%':
                a = (int)do_dec_dec(src1) % (int)do_dec_dec(src2);
                break;
            case '&':
                a = (int)do_dec_dec(src1) & (int)do_dec_dec(src2);
                break;
            case '|':
                a = (int)do_dec_dec(src1) | (int)do_dec_dec(src2);
                break;
            case '^':
                a = (int)do_dec_dec(src1) ^ (int)do_dec_dec(src2);
                break;
            default:
                printf("операция не определена\n");
                return -1;
        }
    }
    else
    {
        printf("некорректный ввод (несимметричный)\n");
        return -1;
    }
    printf("%d\n", a);
    free(src1);
    free(src2);
    free(src3);
    free(str);
    return 0;
}





















