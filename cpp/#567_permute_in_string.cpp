#include <string>
#include <unordered_map>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        // storing character counts of s1 - using the anagram conception
        std::unordered_map<char, int> charCount;
        for (char c : s1) {
            charCount[c]++;
        }

        // sliding window variables
        int left = 0;
        int count = 0;

        // Iterate s2
        for (int right = 0; right < (int)s2.size(); ++right) {
            char currentChar = s2[right];

            // check if the current character is in s1's hashmap and its count 
            // is greater than 0
            if (charCount.find(currentChar) != charCount.end() && 
                                                0 < charCount[currentChar]) {
                --charCount[currentChar]; // Decrement the character count
                ++count; // Increment the total count of characters found from s1
            } else {
                // update window size (move left until we find the same 
                // character) and adjust counts
                while (s2[left] != currentChar) {
                    ++charCount[s2[left]];
                    --count;
                    ++left;
                }
                // Move left one step to the right to continue the search
                left++; 
            }

            // If we have found all characters from s1 in the current window
            if (s1.size() == count) {
                return true;
            }
        }

        return false;
    }
};
