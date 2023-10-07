#include <stdio.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverseString(char *s, int sSize)
{
    if (NULL == s || 1 >= sSize)
    {
        return;
    }

    int left = 0;
    int right = sSize - 1;

    while (left < right)
    {
        swap(&s[left], &s[right]);
        ++left;
        --right;
    }
}

int main()
{
    char str[] = "Hello, World!";
    int length = sizeof(str) - 1;

    printf("Original string: %s\n", str);

    reverseString(str, length);

    printf("Reversed string: %s\n", str);

    return 0;
}
