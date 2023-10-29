#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (1 == nums.size()){
            return nums[0];
        }

        int res = nums[0]; 
        for (int i = 1; i < (int)nums.size(); ++i){
            res = res ^ nums[i];
            // XORing the same number twice results in 0.
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,2,1};

    cout << sol.singleNumber(nums) << endl;

    return 0;
}