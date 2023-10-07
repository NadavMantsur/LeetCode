#include <stdio.h>  /*printf*/
#include <string.h> /*strlen*/
#include <stddef.h> /*size_t*/

static int IsSpace(char c);
static int IsZero(char c);
static int IsValidSign(char c);

int myAtoi(char * s)
{
    int sign = 1;
    size_t res = 0;
    int ret = 0;
    int counter = 0;
    int zero_cnt = 0;

    while (1)
    {
        if (IsSpace(*s) && 0 == zero_cnt)
        {
            ++s;
        }
        else if(IsSpace(*s) && 0 != zero_cnt)
        {
            return ret;
        }
        else if (IsZero(*s))
        {
            ++s;
            ++zero_cnt;
        }
        else
        {
            break;
        }
    }

    if (0 < strlen(s) && 0 == zero_cnt)
    {
        if ('-' == *s)
        {
            sign = -1;
            ++s;
        }
        else if ('+' == *s)
        {
            ++s;
        }
    }

    while ('\0' != *s)
    {
        if (0 == counter && '0' == *s)
        {
            while ('0' == *s)
            {
                ++s;
            }
        }
        if (10 < counter)
        {
            res =  2147483648;
            break;
        }

        if (!IsValidSign(*s) || IsSpace(*s))
        {
            break;
        }
            
        res = res * 10 + (*s - '0');
        
        ++counter;
        ++s;
    }

    if ((2147483648 - 1) < res) /*2^31 = 2147483648*/
    {
        if (-1 == sign)
        {
            ret = -2147483648;
        }
        else
        {
            ret = 2147483648 - 1;
        }
    }
    else
    {
        ret = res * sign;
    }

    return ret;
}

static int IsValidSign(char c)
{
    if ((('0' <= c) && ('9' >= c)) || IsSpace(c))
    {
        return 1;
    }

    return 0;
}

static int IsSpace(char c)
{
    if (' ' == c)
    {
        return 1;
    }

    return 0;
}

static int IsZero(char c)
{
    if ('0' == c)
    {
        return 1;
    }

    return 0;
}

int main(void)
{
    char *s1 = "42";
    char *s2 = "-42";
    char *s3 = "  -42";
    char *s4 = "4193 with words";
    char *s5 = "-91283472332";
    char *s6 = "20000000000000000000";
    char *s7 = "18446744073709551617";
    char *s8 = "00000-42a1234";
    char *s9 = "-000000000000001";

    printf("the string: \"%s\" to integer: %d\n", s1, myAtoi(s1));
    printf("the string: \"%s\" to integer: %d\n", s2, myAtoi(s2));
    printf("the string: \"%s\" to integer: %d\n", s3, myAtoi(s3));
    printf("the string: \"%s\" to integer: %d\n", s4, myAtoi(s4));
    printf("the string: \"%s\" to integer: %d\n", s5, myAtoi(s5));
    printf("the string: \"%s\" to integer: %d\n", s6, myAtoi(s6));
    printf("the string: \"%s\" to integer: %d\n", s7, myAtoi(s7));
    printf("the string: \"%s\" to integer: %d\n", s8, myAtoi(s8));
    printf("the string: \"%s\" to integer: %d\n", s9, myAtoi(s9));

    return 0;
}