/*write a program to check if the number is amstrong or not
for example:
armstrong(1634): num of digits = 4 ->
1^4 + 6^4 + 3^4 + 4^4 = 1634 (num)*/

#include <stdio.h>

static int NumOfDigits(int num);
static int PowByN(int num, int n);

int IsArmstrong(int num)
{
    int n = 0;
    int i = 0;
    int sum = 0;
    int origin_num = num;

    n = NumOfDigits(num);

    for (i = 0; i < n; ++i)
    {
        sum += PowByN(num % 10, n);

        num /= 10;
    }

    if (sum == origin_num)
    {
        return 1;
    }
    
    return 0;
}

int NumOfDigits(int num)
{
    int counter = 0;

    while (0 != num)
    {
        ++counter;
        num /= 10;
    }

    return counter;
}

int PowByN(int num, int n)
{
    int i = 0;
    int res = num;

    for (i = 1; i < n; ++i)
    {
        res *= num;
    }

    return res;
}

int main(void)
{
    int num1 = 1634;
    int num2 = 1643;

    printf("IsArmstrong(%d) = %d\n", num1, IsArmstrong(num1));
    printf("IsArmstrong(%d) = %d\n", num2, IsArmstrong(num2));
    return 0;
}