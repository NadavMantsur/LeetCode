//12. Integer to Roman

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    string intToRoman(int num) 
    {
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result = "";

        for (int i = 0; i < values.size(); ++i)
        {        
            while (num >= values[i])
            {
                result += symbols[i];
                num -= values[i];
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 4, 5, 9, 10, 100, 1992};

    for (auto iter : nums)
    {
        cout << iter << "=>" << sol.intToRoman(iter) << endl;
    }
    return 0;
}
