//16. 3Sum Closest

// Given an integer array nums of length n and an integer target, 
// find three integers in nums such that the sum is closest to target.
// Return the sum of the three integers.
// You may assume that each input would have exactly one solution.

#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <cmath>     // abs

using namespace std;

class Solution
{
public:
    int ThreeSumClosest(vector<int>& nums, int target)
    {
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];
        int minDiff = abs(target - closestSum);
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; ++i)
        {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(target - sum);
                
                if (diff < minDiff)
                {
                    minDiff = diff;
                    closestSum = sum;
                }
                
                if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        
        return closestSum;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    int res = sol.ThreeSumClosest(nums, target);

    cout << "The closest sum is: " << res << endl;

    return 0;
}

