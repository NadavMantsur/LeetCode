/*Given a string s, find the length of the longest 
substringwithout repeating characters.

ex1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

*/

#include <stdio.h>
#include <stddef.h>
#include <string.h>

void InitLut(int lut[])
{
    size_t i = 0;

    for (i = 0; i < 256; ++i)
    {
        lut[i] = 0;
    }
}

int lengthOfLongestSubstring(char* s)
{
    int lut[256] = {0};

    int max_len = 0;
    int curr_len = 0;

    if (' ' == *s)
    {
        curr_len = 1;
        max_len = 1;
        lut[*s] = 1;

        ++s;
    }

    while('\0' != *s)
    {  
        if (0 == lut[*s])
        {
            lut[*s] = 1; 
            ++curr_len;

            ++s;
        }
        else
        {
            s = s - curr_len + 1;

            InitLut(lut);

            if (curr_len > max_len)
            {
                max_len = curr_len;
            }

            curr_len = 0;
        }
    }
    
    if (curr_len > max_len)
    {
        max_len = curr_len;
    }

    return max_len;
}


int main()
{
    char* s1 = "abcabcbb";
    printf("The max substring length of s1: %d\n", lengthOfLongestSubstring(s1));

    char* s2 = "bbbbbb";
    printf("The max substring length of s2: %d\n", lengthOfLongestSubstring(s2));

    char* s3 = "pwwkew";
    printf("The max substring length of s3: %d\n", lengthOfLongestSubstring(s3));

    char* s4 = " ";
    printf("The max substring length of s4: %d\n", lengthOfLongestSubstring(s4));

    char* s5 = " abcabcbb";
    printf("The max substring length of s5: %d\n", lengthOfLongestSubstring(s5));

    char* s6 = "  ";
    printf("The max substring length of s6: %d\n", lengthOfLongestSubstring(s6));

    char* s7 = "au";
    printf("The max substring length of s7: %d\n", lengthOfLongestSubstring(s7));

    char* s8 = "dvdf";
    printf("The max substring length of s8: %d\n", lengthOfLongestSubstring(s8));

    return 0;
}