// Given a non-negative integer x, return the square root of x rounded down to 
// the nearest integer.

#include <iostream>

using namespace std;

// Newton-Raphson
// The basic idea of the Newton-Raphson method is to iteratively refine an 
// estimate of the square root of a number until it converges to an accurate
//  value. sqrt is used to store the estimate of the square root, and temp is 
// used to track changes in sqrt during iterations.
// class Solution
// {
// public:
//     int mySqrt(int x)
//     {
//         int sqrt = x / 2;
//         int temp = 0;

//         while (sqrt != temp)
//         {
//             temp = sqrt;
//             sqrt = (sqrt + (x / sqrt)) / 2;
//         }

//         return sqrt;
//     }
// };

// binary search - generaly mor efficient
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x <= 1)
        {
            return x; // Base case: sqrt(0) = 0, sqrt(1) = 1
        }

        int left = 1, right = x;
        int result = 0;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            
            // Check if mid * mid is less than or equal to x
            // if ((mid * mid) <= x) //runtime error
            if (mid <= x / mid)
            {
                result = mid;

                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return result;
    }
};


int main()
{
    Solution sol;

    int n = 36;

    cout << "the root of " << n << ": " << sol.mySqrt(n) << endl;

    return 0;
}