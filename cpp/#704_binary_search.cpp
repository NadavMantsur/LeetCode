#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right){
            int mid = (right - left) / 2 + left;

            if (target == nums[mid]){
                return mid;
            }
            else if (target < nums[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    cout << sol.search(nums, target) << endl;

    return 0; 
}