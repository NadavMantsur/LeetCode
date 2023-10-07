#include <stdio.h>

/*static void Swap(int *a, int *b);*/

int fib(int n)
{
    int i = 0;
    int prev_prev = 0, prev = 1;
    int temp = 0;

    if (0 == n)
    {
        return prev_prev;
    }

    if (1 == n)
    {
        return prev;
    }

    for (i = 2; i <= n; ++i)
    {
        temp = prev_prev + prev;
        prev_prev = prev;
        prev = temp;

        /*Swap(&prev_prev, &prev); do the same*/
    }

    return prev;
}

/*void Swap(int *a, int *b)
{
    int temp = *a + *b;
    *a = *b;
    *b = temp;
}*/


int FibRec(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return FibRec(n - 1) + FibRec(n - 2);
}


int main(void)
{
    int n = 4;

    printf("fib(%d) = %d\n", n, fib(n));

    printf("FibRec(%d) = %d\n", n, FibRec(n));

    return 0;
}