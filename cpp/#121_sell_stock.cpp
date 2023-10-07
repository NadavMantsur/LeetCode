#include <iostream>
#include <vector>
#include <climits> //INT_MAX

using namespace std;

class Solution 
{
public:
    int maxProfit(vector<int>& prices)
    {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices)
        {
            // Update the minimum price seen so far.
            minPrice = min(minPrice, price);
            
            // Calculate potential profit and update maximum profit.
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};


int main()
{
    Solution sol;

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "the max profit: " << sol.maxProfit(prices) << endl;

    return 0;
}