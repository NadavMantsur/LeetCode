// Given an integer array nums and an integer val, remove all occurrences of val 
// in nums in-place. The order of the elements may be changed. 
// Then return the number of elements in nums which are not equal to val.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == val)
            {
                nums.erase(nums.begin() + i);
                --i;
            }
        }
    
        return (int)nums.size();
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    cout << sol.removeElement(nums, val) << endl;

    return 0;
}