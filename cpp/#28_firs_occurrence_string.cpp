// Given two strings needle and haystack, return the index of the first 
// occurrence of needle in haystack, or -1 if needle is not part of haystack.

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        size_t index = haystack.find(needle);

        if (index != string::npos)
        {
            return static_cast<int>(index);
        }
        
        return -1;
    }
};

int main()
{
    Solution sol;
    string haystack = "hello";
    string needle = "ll";
    
    int index = sol.strStr(haystack, needle);
    cout << "Index of first occurrence: " << index << endl;

    return 0;
}
