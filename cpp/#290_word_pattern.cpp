#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

class Solution{
public:     
    bool wordPattern(std::string pattern, std::string s) {
        std::unordered_map<char, std::vector<int>> charMap;
        std::unordered_map<std::string, std::vector<int>> wordMap;

        std::istringstream ss(s);
        std::string word;
        int index = 0;

        while (ss >> word) {
            // If pattern index exceeds pattern length, return false
            if (index >= pattern.size()) {
                return false;
            }

            // Check if the current character in pattern is already mapped
            char currentChar = pattern[index];
            if (charMap.find(currentChar) == charMap.end()) {
                charMap[currentChar] = {index};
            } else {
                charMap[currentChar].push_back(index);
            }

            // Check if the current word is already mapped
            if (wordMap.find(word) == wordMap.end()) {
                wordMap[word] = {index};
            } else {
                wordMap[word].push_back(index);
            }

            // Compare the indexes where the current character and word appear.
            // comparing the two maps is not efficient in case the string is too 
            // long.
            if (charMap[currentChar] != wordMap[word]) {
                return false;
            }

            index++;
        }

        // If pattern index is not equal to pattern length, return false
        return index == pattern.size();
    }

};

int main() {
    Solution sol;
    string pattern = "abba";
    string str = "dog cat cat dog";

    if (sol.wordPattern(pattern, str)) {
        cout << "True = match" << endl;
    } 
    else {
        cout << "False = not match" << endl;
    }

    return 0;
}