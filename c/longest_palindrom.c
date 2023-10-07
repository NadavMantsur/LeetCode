#include <stdio.h>
#include <string.h> /*strlen, strncpy*/
#include <stddef.h> /*size_t*/
#include <stdlib.h> /*malloc*/

static size_t IsPalindrom(char *s, size_t left, size_t right);

char* longestPalindrome(char* s)
{
    size_t len = strlen(s);
    size_t start = 0;
    size_t max_len = 1;
    size_t i = 0, j = 0;
    char* result;

    if (len < 2)
    {
        return s;
    }

    for (i = 0; i < len - 1; ++i)
    {
        for (j = i + 1; j < len; ++j)
        {
            if ((j - i + 1 > max_len) && IsPalindrom(s, i, j))
            {
                start = i;
                max_len = j - i + 1;
            }
        }
    }

    result = (char*)malloc((max_len + 1) * sizeof(char));
    strncpy(result, s + start, max_len);
    result[max_len] = '\0';

    return result;
}

size_t IsPalindrom(char *s, size_t left, size_t right)
{
    while (left <= right)
    {
        if (s[left] != s[right])
        {
            return 0;
        }

        ++left;
        --right;
    }

    return 1;
}

int main()
{
    char* str = "babad";
    char* palindrome = longestPalindrome(str);

    printf("Longest palindromic substring: %s\n", palindrome);

    free(palindrome);

    return 0;
}

