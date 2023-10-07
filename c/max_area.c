/*You are given an integer array height of length n. 
There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, 
such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
*/

#include <stdio.h>
#include <stdlib.h>   /*min*/

/*the naive solution - O(n^2)*/
static int min(int a, int b);

int maxAreaNaive(int* height, int heightSize)
{
    int i = 0, j = 0;
    int max_area = 0;
    int min_height = 0;

    for (i = 0; i < heightSize - 1; ++i)
    {
        for (j = i + 1; j < heightSize; ++j)
        {
            if (min(height[i], height[j]) * (j - i) > max_area)
            {
                max_area = min(height[i], height[j]) * (j - i);
            }
        }
    }
    
    return max_area;
}

int min(int a, int b)
{
    return a < b ? a : b;
}*/


/*the best solution - O(n)*/
int maxArea(int* arr, int N)
{
    int max = 0, test, i = 0, j = N - 1;

    while(j > i)
    {
        test = arr[i];
        
        if (test > arr[j])
        {
            test = arr[j];
        }

        test = (j - i) * test;

        if (max < test)
        {
            max = test;
        }

        if (arr[i] < arr[j])
        {
            ++i ;
        }

        else
        {
            --j;
        }
    }

    return max;
}

int main(void)
{
    int height[9] = {1,8,6,2,5,4,8,3,7};
    
    printf("the max area: %d\n", maxArea(height, 9));

    return 0;
}