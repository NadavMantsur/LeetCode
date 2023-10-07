// nums is sorted
#include <iostream>
#include <vector>

using namespace std;

// time complexity O(n)
// class Solution
// {
// public:
//     int searchInsert(vector<int>& nums, int target)
//     {
//         size_t idx = 0;

//         for (auto num:nums)
//         {
//             if (num < target)
//             {
//                 ++idx;
//             }
//             else
//             {
//                 return idx;
//             }
//         }

//         return nums.size();
//     }
// };

// time complexity O(logn)
class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 3, 5, 6};
    vector<int> targets = {0, 5, 2, 7};
    vector<int> expected = {0, 2, 1, 4};

    for (size_t i = 0; i < targets.size(); ++i)
    {
        if (sol.searchInsert(nums, targets[i]) != expected[i])
        {
            cout << "test failed in case: " << targets[i] << endl;
        }
    }

    return 0;
}