// Given two strings s and t, return true if t is an anagram of s, 
// and false otherwise.

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isAnagram(const string& s, const string& t)    {
        if (s.length() != t.length())
        {
            return false;
        }
        
        // Use a hashmap to count the frequency of characters in both strings
        unordered_map<char, int> freqMap;
        
        // Increment the frequency for characters in string s
        for (char c : s)
        {
            ++freqMap[c];
        }
        
        // Decrement the frequency for characters in string t
        for (char c : t)
        {
            // if (freqMap.find(c) == freqMap.end())
            // {
            //     return false; // Character not present in s
            // }

            --freqMap[c];

            // if (freqMap[c] < 0)
            // {
            //     return false; // More occurrences of character c in t than in s
            // }
        }
        
        // Check if all character frequencies are zero
        for (auto& entry : freqMap)
        {
            if (entry.second != 0)
            {
                return false;
            }
        }
        
        return true;
    }
};

int main()
{
    Solution sol;
    
    string s = "anagram";
    string t = "nagaram";
    
    if (sol.isAnagram(s, t))
    {
        cout << "t is an anagram of s." << endl;
    }
    else
    {
        cout << "t is ~not~ an anagram of s." << endl;
    }

    return 0;
}
