// Given an integer array nums sorted in non-decreasing order, remove the 
// duplicates in-place such that each unique element appears only once. 
// The relative order of the elements should be kept the same. 
// Then return the number of unique elements in nums.

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        for (size_t i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                nums.erase(nums.begin() + i);
                --i;
            }
        }

        return nums.size();
    }
};

int main()
{
    Solution sol;

    vector <vector<int>> nums = {{1, 1, 2}, {0, 0, 1, 1, 1, 2, 2, 3, 3, 4},
                                {1}, {}, {1, 1}};

    vector<int> expected = {2, 5, 1, 0, 1};

    for(size_t i = 0; i < nums.size(); ++i)
    {
        if (sol.removeDuplicates(nums[i]) != expected[i])
        {
            cout << "test failed" << endl;
            cout << "case number: " << i + 1 <<endl;
            cout << "expected: "<< expected[i] << endl;
        }
    }

    

    return 0;
}