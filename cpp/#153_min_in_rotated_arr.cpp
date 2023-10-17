#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // time complexity O(logn)
    int findMin(vector<int>& nums) {
        int minElement = nums[0];
        int left = 0;
        int right = nums.size() - 1;

        while (left < right){
            int mid = (right - left) / 2 + left;
            
            if (nums[left] < nums[mid]){
                if (nums[left] < nums[right]){
                    right = mid - 1;
                    minElement = min(minElement, nums[left]);
                }
                else{
                    left = mid + 1;
                    minElement = min(minElement, nums[right]);
                }
            }

            else{
                if (nums[mid] < nums[right]){
                    minElement = min(minElement, nums[mid]);
                    right = mid - 1;
                }
                else{
                    minElement = min(minElement, nums[right]);
                    left = mid + 1;
                }
            }
        }

        return minElement;
    }

    // shorter solution
    int findMinShortSolution(vector<int>& nums) {
        int minElement = nums[0];
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            minElement = min(nums[mid], minElement);

            if (nums[mid] < nums[right]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return minElement;
    }

    // shortest solution
    int findMinShortest(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[right]) {
                right = mid; // mid could be the minimum element, so we 
                             // include it in the search space
            } else {
                left = mid + 1;
            }
        }

        // Left points to the minimum element
        return nums[left];
    }

};

int main(){
    Solution sol;
    vector<vector<int>> nums = {{3,4,5,1,2}, {4,5,6,7,0,1,2}, {11,13,15,17}, 
                                {4,5,1,2,3}};

    for (auto num : nums){
        cout << sol.findMin(num) << endl;
        cout << sol.findMinShortSolution(num) << endl;
        cout << sol.findMinShortest(num) << endl;
    }
    return 0;
}