// 75. Sort Colors

// Given an array nums with n objects colored red, white, or blue, sort them in-place 
// so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

#include <iostream>
#include <vector>   //vector
#include <algorithm> //swap

using namespace std;

class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        auto low = nums.begin();
        auto high = nums.end() - 1;
        auto mid = nums.begin();

        while (mid <= high)
        {

            if (0 == *mid)
            {
                // low.swap(mid);
                iter_swap(low, mid);

                ++low;
                ++mid;
            }
            else if (1 == *mid)
            {
                ++mid;
            }
            else
            {
                iter_swap(high, mid);

                --high;
            }
        }
    }
};


int main()
{
    Solution sol;

    vector<int> colors = {2,0,1};

    sol.sortColors(colors);

    auto print = [](const int& n) { std::cout << ' ' << n; };
    for_each(colors.begin(), colors.end(), print);
    cout << endl;

    return 0;
}