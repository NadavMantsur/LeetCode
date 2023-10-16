#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxLength = 0;
        int maxRepeatCharCount = 0;
        int windowSize = 0;
        unordered_map<char, int> charCount;

        for (int right = 0; right < (int)s.size(); ++right) {
            charCount[s[right]]++;
            // tracking the maximum count of a single character in the window. 
            maxRepeatCharCount = max(maxRepeatCharCount, charCount[s[right]]);

            // If the number of characters to be replaced is greater than k,
            // shrink the window from the left side.
            windowSize = right - left + 1;
            while ((windowSize - maxRepeatCharCount) > k) {
                --charCount[s[left]];
                ++left;
                windowSize = right - left + 1;
            }

            // Update the maximum length of the substring with the same letter.
            maxLength = max(maxLength, windowSize);
        }

        return maxLength;
    }   
};

int main(){
    Solution sol;
    vector<string> strings = {"ABBA", "AABABBA"};
    vector<int> nums = {2, 1};

    for (int i = 0; i < (int)strings.size(); ++i){
        cout << sol.characterReplacement(strings[i], nums[i]) << endl;
    }

    return 0;
}
