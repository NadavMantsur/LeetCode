#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        if (s.length() != indices.size()) {
            throw runtime_error("Input lengths are not equal");
        }

        string res = s;

        for (size_t i = 0; i < s.length(); ++i)
        {
            res[indices[i]] = s[i];
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> indices = {4,5,6,7,0,2,1,3};
    string s = "codeleet";

    cout << sol.restoreString(s, indices) << endl;

    return 0;
}