// divide two integers without using multiplication, division, and mod operator.

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (0 == divisor && 0 != dividend)
        {
            throw invalid_argument("Divisor cannot be zero");
        }

        else if (dividend == 0)
        {
            return 0;
        }

        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }

        else if (dividend == INT_MIN && divisor == 1)
        {
            return INT_MIN;
        }

        else if (dividend == INT_MAX && divisor == -1)
        {
            return INT_MAX * -1;
        }

        else if (dividend == INT_MAX && divisor == 1)
        {
            return INT_MAX;
        }

        int cnt = 0;
        int dividend_sign = (dividend >= 0) ? 1 : -1;
        int divisor_sign = (divisor >= 0) ? 1 : -1;

        long long long_dividend = abs((long long)dividend);
        long long long_divisor = abs((long long)divisor);

        while (long_dividend >= long_divisor)
        {
            long_dividend -= long_divisor;
            ++cnt;
        }

        return cnt * dividend_sign * divisor_sign;
    }
};


int main()
{
    Solution sol;

    vector<int> dividends = {10, 7, -1, 2147483647, 0};
    vector<int> divisors = {3, -3, 1, -1, 0};

    for (size_t i = 0; i < dividends.size(); ++i)
    {
        cout << dividends[i] << " / " << divisors[i] << " = " << 
                                    sol.divide(dividends[i], divisors[i]) << endl;
    }

    return 0;
}