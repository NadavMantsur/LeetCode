#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows)
{
    int len = strlen(s);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int interval = 2 * numRows - 2;
    int index = 0;
    int i = 0, j = 0;

    if (numRows == 1 || numRows >= strlen(s))
    {
        return s;
    }    

    for (i = 0; i < numRows; ++i)
    {
        for (j = i; j < len; j += interval)
        {
            result[index++] = s[j];

            if (0 != i && i != numRows - 1)
            {
                int next = j + interval - 2 * i;
                
                if (next < len)
                {
                    result[index++] = s[next];
                }
            }
        }
    }

    result[len] = '\0';
    return result;
}

int main(void)
{
    char input[] = "PAYPALISHIRING"; /*PINALSIGYAHRPI*/
    int numRows = 4;
    char* result = convert(input, numRows);

    if (strcmp(input, result))
    {
        printf("convert success\n");
    }

    free(result);

    return 0;
}
