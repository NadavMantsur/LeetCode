// Given an array of integers nums, find the next permutation of nums.
// The replacement must be in place and use only constant extra memory.

#include <iostream>
#include <vector>
#include <algorithm> //reverse

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        int n = nums.size();
        int i = n - 2;
        
        // Find the first element that breaks the decreasing pattern
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            --i;
        }
        
        if (i >= 0)
        {
            int j = n - 1;
            // Find the first element greater than nums[i]
            while (j >= 0 && nums[j] <= nums[i])
            {
                --j;
            }
            // Swap nums[i] and nums[j]
            swap(nums[i], nums[j]);
        }
        
        // Reverse the subarray to the right of i
        reverse(nums.begin() + i + 1, nums.end());
    }
};

// using the inbuild function
// class Solution
// {
// public:
//     void nextPermutation(std::vector<int>& nums)
//     {
//         std::next_permutation(nums.begin(), nums.end());
//     }
// };


int main()
{
    Solution sol;

    vector<int> nums = {1, 2, 3};

    cout << "the next permutation of nums: {";
    for (auto num : nums)
    {
        cout << num;
    }
    cout << "}: ";

    sol.nextPermutation(nums);

    cout << "{";
    for (auto num : nums)
    {
        cout << num;
    }
    cout << "}" << endl;

    return 0;
}
