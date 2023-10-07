// 14. Longest Common Prefix
// Write a function to find the longest common prefix string amongst an array 
// of strings.
// If there is no common prefix, return an empty string "".

#include <iostream>
#include <string>       //string
#include <vector>       //vector
#include <algorithm>    //sort
#include <cassert>      //assert

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs_)
    {
        int n = strs_.size();
        string ans;

        sort(strs_.begin(), strs_.end());
        string a = strs_[0];
        string b = strs_[n-1];

        for(size_t i = 0; i < a.size(); ++i)
        {
            if(a[i] == b[i])
            {
                ans += a[i];
            }
            else break;
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    
    // Test case 1
    vector<string> input1 = {"flower", "flow", "flight"};
    string expected1 = "fl";
    string result1 = solution.longestCommonPrefix(input1);
    assert(result1 == expected1);
    
    // Test case 2
    vector<string> input2 = {"dog", "racecar", "car"};
    string expected2 = "";
    string result2 = solution.longestCommonPrefix(input2);
    assert(result2 == expected2);
    
    // Test case 3
    vector<string> input3 = {"apple", "app", "application"};
    string expected3 = "app";
    string result3 = solution.longestCommonPrefix(input3);
    assert(result3 == expected3);
    
    cout << "All test cases passed!" << endl;
    
    return 0;
}