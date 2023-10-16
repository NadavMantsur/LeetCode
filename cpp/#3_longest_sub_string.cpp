#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLen = 0;
        unordered_map<char, int> chars; //{char, idx} 

        for (int right = 0; right < (int)s.size(); ++right){
            if (chars.find(s[right]) != chars.end()){
                left = max(left, chars[s[right]] + 1);
            }
            
            chars[s[right]] = right;

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main(){
    Solution sol;
    vector<string> strings = {"abcabcbb", "abba"};

    for (string s : strings){
        cout << sol.lengthOfLongestSubstring(s) <<endl;
    }
    
    return 0;
}