//  22. Generate Parentheses
// Given n pairs of parentheses, write a function to generate all combinations 
// of well-formed parentheses.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        generateParenthesisRec(n, 0, 0, "", result);
        return result;
    }

private:
    void generateParenthesisRec(int n, int openCnt, int closeCnt, string curr, 
                                                        vector<string>& result)
    {
        if (openCnt == n && closeCnt == n)
        {
            result.push_back(curr);
            return;
        }

        // adding an opening parenthesis
        if (openCnt < n)
        {
            generateParenthesisRec(n, openCnt + 1, closeCnt, curr + "(", result);
        }

        // adding a closing parenthesi
        if (closeCnt < openCnt)
        {
            generateParenthesisRec(n, openCnt, closeCnt + 1, curr + ")", result);
        }
    }
};

int main()
{
    Solution solution;
    int n = 3;
    vector<string> result = solution.generateParenthesis(n);

    // Print the size of the resulting vector
    cout << "Number of combinations: " << result.size() << endl;

    // Print the resulting vector
    for (const string& str : result)
    {
        cout << str << endl;
    }

    return 0;
}
