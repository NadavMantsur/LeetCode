#include <iostream>
#include <string>
#include <vector>
#include <cctype> //tolower, isdigit, isalpha, isalnum

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int leftIdx = 0;
        int rightIdx = s.size() - 1;

        while (leftIdx <= rightIdx){
            if (isalnum(s[leftIdx]) && isalnum(s[rightIdx])){
            // if ((isalpha(s[leftIdx]) && isalpha(s[rightIdx])) ||
            //     (isdigit(s[leftIdx]) && isdigit(s[rightIdx]))){
                if (tolower(s[leftIdx]) != tolower(s[rightIdx])){
                    return false;
                }

                ++leftIdx;
                --rightIdx;
            }
            else if (!isalnum(s[rightIdx])){
                    --rightIdx;
            }
            else if (!isalnum(s[leftIdx])){
                    ++leftIdx;
            }
        }

        return true;
    }
};

int main(){
    Solution sol;
    vector<string> phrases = {"A man, a plan, a canal: Panama",
                        "race a car",
                        " "};

    for (string s : phrases){
        cout << s.c_str() << "is palindrom? " << sol.isPalindrome(s) << endl;
    }

    return 0;
}