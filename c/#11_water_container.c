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