#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp; // for storing the current permutation
        vector<bool> used(nums.size(), false); // for keeping track of used elements

        permuteHelper(nums, temp, used, res);
        return res;
    }

private:
    void permuteHelper(vector<int>& nums, vector<int>& temp, vector<bool>& used, vector<vector<int>>& res) {
        // add the current permutation to the result
        if (temp.size() == nums.size()) {
            res.push_back(temp); 
            return;
        }

        for (int i = 0; i < (int)nums.size(); ++i) {
            if (!used[i]) {
                temp.push_back(nums[i]); 
                used[i] = true; 
                permuteHelper(nums, temp, used, res); 
                used[i] = false; 
                temp.pop_back();
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = sol.permute(nums);

    for (auto vector : res) {
        cout << "[";
        for (auto num : vector) {
            cout << num << ",";
        }
        cout << "]" << endl;
    }
}
