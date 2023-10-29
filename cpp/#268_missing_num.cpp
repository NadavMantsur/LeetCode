#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for (int i = 0; i < (int)nums.size(); ++i){
            res ^= i ^ nums[i]; 
            // XORing the same number twice results in 0.
            // XORed with 0 given the number itself.
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,0,1};

    cout << sol.missingNumber(nums) << endl;

    return 0;
}