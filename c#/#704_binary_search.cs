using System;

public class Solution
{
    public int Search(int[] nums, int target)
    {
        int left = 0;
        int right = nums.Length - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (target == nums[mid])
            {
                return mid;
            }
            else if (target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return -1;
    }
}

public class Program
{
    public static void Main()
    {
        Solution sol = new Solution();

        int[] nums = {-1, 0, 3, 5, 9, 12};
        int target = 9;

        Console.WriteLine(sol.Search(nums, target));
        
    }
}