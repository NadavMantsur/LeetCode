#include <stdio.h>
#include <limits.h> /*INT_MIN, INT_MAX*/
/*INT_MIN -2147483647 - 1 = -2147483648*/
/*INT_MAX 2147483647*/

int reverse(int x)
{
    int reversed = 0;
    
    while (0 != x)
    {
        if (reversed > INT_MAX / 10 || reversed < INT_MIN / 10)
        {
            return 0;
        }
        
        reversed = reversed * 10 + (x % 10);
        x /= 10;
    }
    
    return reversed;
}

int main(void)
{
    int num = 123;
    printf("the origin: %d, the reversed: %d\n", num, reverse(num));
    
    return 0;
}