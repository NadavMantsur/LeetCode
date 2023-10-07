//392. Is Subsequence
// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

// A subsequence of a string is a new string that is formed from the original string by 
// deleting some (can be none) of the characters without disturbing the relative positions 
// of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        auto iter_s = s.begin();
        auto iter_t = t.begin();

        while ((s.end() != iter_s) && (t.end() != iter_t))
        {

      
            if (*iter_s == *iter_t)
            {
                ++iter_s;
            }

            ++iter_t;
        }

        if (s.end() == iter_s)
        {
            return true;
        }
        
        return false;
    }
};


int main()
{
    string s = "abc";
    string t = "ahbgdc";
    
    Solution sol;

    cout << sol.isSubsequence(s, t) << endl;
}