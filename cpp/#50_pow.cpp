#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0 || x == 1)
        {
            return x;
        }

        if (n == 0)
        {
            return 1;
        }

        long long ln = n;
        if (n < 0)
        {
            x = 1 / x;
            ln *= -1;
        }

        double res = 1.0;
        while (ln > 0)
        {
            if (ln % 2 == 1)
            {
                res *= x;
            }

            x *= x;
            ln /= 2; // This will significantly reduce the number of multiplications needed
        }

        return res;
    }
};

int main()
{
    Solution sol;

    vector<double> x = {2, 2.1, 2, 2, -1};
    vector<int> n = {10, 3, -2, -2147483648, 2147483647};

    for (size_t i = 0; i < x.size(); ++i)
    {
        cout << x[i] << "^" << n[i] << "= " << sol.myPow(x[i], n[i]) << endl;
    }

    return 0;
}