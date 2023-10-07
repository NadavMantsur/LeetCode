// You can solve this problem using Floyd's Tortoise and Hare (Cycle Detection) 
// algorithm, which is designed to find a cycle in a linked list. In this case, 
// you can treat the array as a linked list where the values of the array 
// represent the indices to jump to. Since there is a repeated number, there 
// will be a cycle in this linked list.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //  Floyd's Tortoise and Hare: do-while loop - O(n)
    // int findDuplicate(vector<int>& nums) {
    //     int tortoise = nums[0];
    //     int hare = nums[0];

    //     // Find the intersection point of the two pointers.
    //     do {
    //         tortoise = nums[tortoise];
    //         hare = nums[nums[hare]];
    //     } while (tortoise != hare);

    //     // Find the entrance to the cycle.
    //     tortoise = nums[0];
    //     while (tortoise != hare) {
    //         tortoise = nums[tortoise];
    //         hare = nums[hare];
    //     }

    //     return tortoise;
    // }

    // Cycle Detection - O(n)
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // to find the intersection point.
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (slow == fast){
                break;
            }
        }

        // to find  the entrance to the cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }

    // linear solution: using binary search - O(nlogn)
    // int findDuplicate(std::vector<int>& nums) {
    //     int left = 1;
    //     int right = nums.size() - 1;
        
    //     while (left < right) {
    //         int mid = left + (right - left) / 2;
    //         int count = 0;
            
    //         for (int num : nums) {
    //             if (num <= mid) {
    //                 count++;
    //             }
    //         }
            
    //         if (count > mid) {
    //             right = mid;
    //         } else {
    //             left = mid + 1;
    //         }
    //     }
        
    //     return left;
    // }
};

int main(){
    Solution sol;
    vector<int> nums = {1,3,4,2,2};
    cout << sol.findDuplicate(nums) << endl;
    return 0;
}

// How can we prove that at least one duplicate number must exist in nums?
// Pigeonhole Principle - The Pigeonhole Principle states that if you have more 
// "pigeons" (items) than "pigeonholes" then at least one pigeonhole must 
// contain more than one pigeon.
// https://he.wikipedia.org/wiki/%D7%A2%D7%A7%D7%A8%D7%95%D7%9F_%D7%A9%D7%95%D7%91%D7%9A_%D7%94%D7%99%D7%95%D7%A0%D7%99%D7%9D