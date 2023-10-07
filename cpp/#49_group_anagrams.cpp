#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // time complexity: O(N * Klog(K))
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        // Sort the characters in the each string
        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());

            // Use the sorted string as a key in the unordered_map.
            anagramGroups[sortedStr].push_back(str);
        }

        // convert to vector
        vector<vector<string>> result;
        for (const auto& pair : anagramGroups) {
            result.push_back(pair.second);
        }

        return result;
    }

    // time complexity: O(N^2 * K)
    // bool areAnagrams(const string& s1, const string& s2) {
    //     if (s1.length() != s2.length()) {
    //         return false;
    //     }

    //     vector<int> count(26, 0);

    //     for (char c : s1) {
    //         count[c - 'a']++;
    //     }

    //     for (char c : s2) {
    //         count[c - 'a']--;
    //         if (count[c - 'a'] < 0) {
    //             return false;
    //         }
    //     }

    //     return true;
    // }

    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     vector<vector<string>> result;

    //     for (const string& str : strs) {
    //         bool added = false;
    //         for (vector<string>& group : result) {
    //             if (areAnagrams(group[0], str)) {
    //                 group.push_back(str);
    //                 added = true;
    //                 break;
    //             }
    //         }

    //         if (!added) {
    //             result.push_back({str});
    //         }
    //     }

    //     return result;
    // }
};

int main() {
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groupedAnagrams = sol.groupAnagrams(strs);

    // Print the grouped anagrams.
    for (const vector<string>& group : groupedAnagrams) {
        for (const string& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
