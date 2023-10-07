// 17. Letter Combinations of a Phone Number

// Given a string containing digits from 2-9 inclusive, return all possible 
// letter combinations that the number could represent.

// Note that 1 does not map to any letters.

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(const string& digits) 
    {
        vector<string> result;

        if (digits.empty()) 
        {
            return result;
        }

        map<char, string> mapping = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        result.push_back("");

        // build new combinations
        for (char digit : digits) 
        {
            string letters = mapping[digit];
            // Create a temporary vector to store updated combinations
            vector<string> temp;

            for (char letter : letters) 
            {
                for (const string& str : result) 
                {
                    // Append the current letter to existing combinations
                    temp.push_back(str + letter);
                }
            }
            // Replace the result vector with the temporary vector
            result = move(temp);
        }

        return result;
    }
};

int main() 
{
    Solution sol;
    string digits = "23";
    vector<string> combinations = sol.letterCombinations(digits);

    cout << "Letter combinations for " << digits << ":\n";

    for (const string& combination : combinations) 
    {
        cout << combination << " ";
    }

    cout << endl;

    return 0;
}

