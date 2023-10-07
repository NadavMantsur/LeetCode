#include <iostream>

using namespace std;

// dynamic programming - fibonacci
// each number in fib serie represent the number of ways
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
        {
            return n;
        }
        
        int prev1 = 1;
        int prev2 = 2;
        int current;
        
        for (int i = 3; i <= n; ++i)
        {
            current = prev1 + prev2;
            prev1 = prev2;
            prev2 = current;
        }
        
        return current;
    }
};

int main()
{
    Solution sol;
    int n = 3;

    cout << "the num of posibles to reach floor " << n << ": " <<
    sol.climbStairs(n) << endl;

    return 0;
}