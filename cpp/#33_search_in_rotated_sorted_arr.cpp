#include <iostream>
#include <vector>
// Given sorted array nums after the possible rotation and an integer target, 
// return the index of target if it is in nums, or -1 if it is not in nums.

using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target)
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
            
            // Check which half is sorted
            if (nums[left] <= nums[mid])    // Left half is sorted
            {   
                if (target >= nums[left] && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else    // Right half is sorted
            {
                
                if (target > nums[mid] && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        
        return -1; // Target not found
    }
};


int main()
{
    Solution sol;

    vector<int> nums = {4,5,6,7,0,1,2};

    cout << "the index: " << sol.search(nums, 0) << endl;

    return 0;
}
