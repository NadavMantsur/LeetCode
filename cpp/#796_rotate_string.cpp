#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // shorter and more efficient solution
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        string concatenated = s + s;

        return concatenated.find(goal) != string::npos;
    }

    // other solution
    // bool rotateString(string s, string goal) {
    //     bool status = false;

    //     if (s.length() != goal.length()){
    //         return false;
    //     }

    //     for (size_t i = 0; i < s.length(); ++i){
    //         s = rotateLeftOnce(s);

    //         if (s == goal)
    //         {
    //             status = true;
    //             break;
    //         }
    //     }

    //     return status;
    // }


// for the other solution
// private:
//     string rotateLeftOnce(string s)
//     {
//         char firstLetter = s[0];

//         for(size_t i = 1; i < s.length(); ++i){
//             s[i - 1] = s[i];
//         }

//         s[s.length() - 1] = firstLetter;

//         return s;
//     }
};


int main()
{
    Solution sol;

    string s = "abcde";
    string goal = "cdeab";

    cout << sol.rotateString(s, goal) << endl;

    return 0;
}