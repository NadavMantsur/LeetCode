#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> ret;

        if (nums.size() == 0)
        {
            return ret;
        }
        
        // O(n^2)
        // for (size_t i = 0; i < nums.size() - 1; ++i)
        // {
        //     int comp = target - nums[i];

        //     for (size_t j = i + 1; j < nums.size(); ++j)
        //     {
        //         if (comp == nums[j])
        //         {
        //             ret.push_back(nums[i]);
        //             ret.push_back(nums[j]);

        //             break;
        //         }
        //     }
        // }

        // O(n) - nums is sorted
        // size_t low = 0;
        // size_t high = nums.size() - 1;

        // while (low < high)
        // {
        //     int sum = nums[low] + nums[high];

        //     if (sum == target)
        //     {
        //         ret.push_back(nums[low]);
        //         ret.push_back(nums[high]);

        //         break;
        //     }
        //     else if (sum < target)
        //     {
        //         ++low;
        //     }
        //     else
        //     {
        //         --high;
        //     }
        // }

        // O(n) - nums is NOT sorted
        // we can use sort and use the solution above -> O(nlogn),
        // or we can use unordered_set
        // unordered_set<int> comp;

        // for (int num:nums)
        // {
        //     if (comp.find(target - num) != comp.end())
        //     {
        //         ret.push_back(num);
        //         ret.push_back(target - num);

        //         break;
        //     }
        //     else
        //     {
        //         comp.insert(num);
        //     }
        // }

        // The same but returns the indexes instead of the values
        unordered_map<int, int> numToIndex;

        for (size_t i = 0; i < nums.size(); ++i)
        {
            int complement = target - nums[i];

            if (numToIndex.find(complement) != numToIndex.end())
            {
                ret.push_back(numToIndex[complement]);
                ret.push_back(i);
                break;
            }
            else
            {
                numToIndex[nums[i]] = i;
            }
        }

        // nums is too large - doesn`t fit the memory
        // using threads


        return ret;
    }

};

int main()
{
    Solution sol;

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> res = sol.twoSum(nums, target);

    if (res.size() == 0)
    {
        cout << "there is no solution" << endl;
    }
    else
    {
        cout << "[" << res[0] << "," << res[1] << "]" << endl;
    }

    return 0;
}