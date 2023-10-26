#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> rows = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
        unordered_map<char, int> rowMap = createRowMap(rows);
        vector<string> result;

        for (const string& word : words) {
            bool status = isInSameRow(word, rowMap);
            
            if (true == status){
                result.push_back(word);
            }
        }

        return result;
    }

private:
    unordered_map<char, int> createRowMap(vector<string> rows){
        unordered_map<char, int> rowMap;

        for (int i = 0; i < 3; ++i) {
            for (char c : rows[i]) {
                rowMap[c] = i;
            }
        }

        return rowMap;
    }

    bool isInSameRow(const string word, unordered_map<char, int> rowMap){
        int rowNum = 0;

        if (isalpha(word[0])){
            rowNum = rowMap[toupper(word[0])];
        }

        for (const char c : word){
            if (!isalpha(c)){
                return false;
            }
            else if (rowMap[toupper(c)] != rowNum){
                return false;
            }
        }

        return true;
    }
};

int main(){
    Solution sol;
    vector<vector<string>> words = {{"Hello","Alaska","Dad","Peace"}, 
                                    {"adsdf","sfd"}};
    vector<vector<string>> expected = {{"Alaska","Dad"}, 
                                       {"adsdf","sfd"}};
    
    for (int i = 0; i < (int)words.size(); ++i){
        vector<string> res = sol.findWords(words[i]);

        if (expected[i] == res){
            cout << "case passed: #" << i << endl;
        }
        else{
            cout << "case failed: #" << i << endl;
        }
    }

    return 0;
}