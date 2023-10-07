// 1823. Find the Winner of the Circular Game

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        vector<int> players(n);

        for (int i = 0; i < n; ++i)
        {
            players[i] = i + 1;
        }

        int index = 0;

        while (1 < players.size())
        {
            index = (index + k - 1) % players.size();
            players.erase(players.begin() + index);
        }

        return players[0];
    }
};

int main()
{
    Solution solution;
    int n = 5;
    int k = 2;
    int winner = solution.findTheWinner(n, k);
    cout << "The winner is: " << winner << endl;

    return 0;
}
