//15. 3Sum

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
// such that i != j, i != k, j != k, and nums[i] + nums[j] + nums[k] == 0.

#include <iostream>
#include <vector>
#include <algorithm> //sort

using namespace std;

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;
        int n = nums.size();
        
        //sorting nums
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; ++i)
        {
            //skip duplicates
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;
            
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                
                if (sum < target)
                {
                    left++;
                }
                else if (sum > target)
                {
                    right--;
                }
                else //sum == target --> sum + target == 0 --> sum == -num[i]
                {
                    //found a triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    //skip duplicates
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    
                    left++;
                    right--;
                }
            }
        }
        
        return result;
    }
};

void printResult(const vector<vector<int>>& result)
{
    for (const auto& triplet : result)
    {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++)
        {
            cout << triplet[i];
            if (i != triplet.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
}

int main()
{
    Solution sol;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result;

    result = sol.threeSum(nums);

    printResult(result);

    return 0;
}
