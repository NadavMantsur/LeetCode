// 18. 4Sum

// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

#include <iostream>
#include <vector>
#include <algorithm>    //sort

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
{
    size_t n = nums.size();
    std::vector<std::vector<int>> result;
    if (n < 4)
    {
		return result;
	}

    // Sort the input array to simplify the process of finding unique quadruplets.
    std::sort(nums.begin(), nums.end());

    for (size_t a = 0; a < n - 3; ++a)
    {
		// nums[i] has become too large, no point in continuing
		if ((long long)nums[a] + nums[a+1] + nums[a+2] + nums[a+3] > target) break;
        // target too small, no point in continuing
		if (target <= 0 and nums[a] > 0) break;
        // nums[i] is so small, even the largest elements cannot help reach the sum
		if ((long long)nums[a] + nums[n-3] + nums[n-2] + nums[n-1] < target) continue; 

        if (a > 0 && nums[a] == nums[a - 1])
            continue;

        for (size_t b = a + 1; b < n - 2; ++b)
        {
            // nums[j] has become too large, no point in continuing
			if ((long long)nums[a] + nums[b] + nums[b+1] + nums[b+2] > target) break;
			// nums[j] is so small, even the largest elements cannot help reach the sum
			if ((long long)nums[a] + nums[b] + nums[n-2] + nums[n-1] < target) continue; 

            if (b > a + 1 && nums[b] == nums[b - 1])
                continue;

            int left = b + 1;
            int right = n - 1;

            while (left < right)
            {
                int sum = (long long)nums[a] + nums[b] + nums[left] + nums[right];
                if (sum == target)
                {
                    result.push_back({nums[a], nums[b], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        ++left;
                    while (left < right && nums[right] == nums[right - 1])
                        --right;
                    ++left;
                    --right;
                }
                else if (sum < target)
                {
                    ++left;
                }
                else
                {
                    --right;
                }
            }
        }
    }

    return result;
}

int main()
{
    std::vector<int> nums = {1, 0, -1, 0, -2, 2}; 
    int target = 0;
    std::vector<std::vector<int>> result = fourSum(nums, target);

    // Printing the quadruplets in the result vector.
    for (const auto& quad : result)
    {
        std::cout << "[";
        for (int num : quad)
        {
            std::cout << num << ", ";
        }
        std::cout << "]" << std::endl;
    }

    std::vector<int> nums2 = {2, 2, 2, 2, 2, 2}; 
    target = 8;
    result = fourSum(nums2, target);

    // Printing the quadruplets in the result vector.
    for (const auto& quad : result)
    {
        std::cout << "[";
        for (int num : quad)
        {
            std::cout << num << ", ";
        }
        std::cout << "]" << std::endl;
    }
    
    std::vector<int> nums3 = {1000000000,1000000000,1000000000,1000000000}; 
    target = 0;
    result = fourSum(nums3, target);

    // Printing the quadruplets in the result vector.
    for (const auto& quad : result)
    {
        std::cout << "[";
        for (int num : quad)
        {
            std::cout << num << ", ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
