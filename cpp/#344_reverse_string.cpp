#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void reverseString(vector<char>& s)
    {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
};

int main()
{
    Solution solution;
    vector<char> str = {'H', 'e', 'l', 'l', 'o', '!', '\0'};

    cout << "Original string: ";
    for (char c : str)
    {
        if (c != '\0')
        {
            cout << c;
        }
    }
    cout << endl;

    solution.reverseString(str);

    cout << "Reversed string: ";
    for (char c : str)
    {
        if (c != '\0')
        {
            cout << c;
        }
    }
    cout << endl;

    return 0;
}
