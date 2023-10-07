#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {// solution for nXn
    //     size_t n = 0;
    //     size_t i = 0;

    //     for (n = 0; n < matrix.size(); ++n)
    //     {
    //         if (matrix[n][n] >= target)
    //         {
    //             break;
    //         }
    //     }

    //     for (i = 0; i < matrix[n].size(); ++i)
    //     {
    //         if (matrix[n][i] == target || matrix[i][n] == target)
    //         {
    //             return true;
    //         }
    //     }

    //     return false;
    // }

    // solution for mXn
        int m = 0, n = matrix[0].size() - 1;

        while (m < (int)matrix.size() && n >= 0)
        {

            if (matrix[m][n] == target)
            {
                return true;
            }
            else if (matrix[m][n] > target)
            {
                --n;
            }
            else
            {
                ++m;
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 18;

    cout << sol.searchMatrix(matrix, target) << endl;

    return 0;
}