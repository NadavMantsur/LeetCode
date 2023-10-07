#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;

        int leftIdx = 0;
        int rightIdx = numbers.size() - 1;

        while (leftIdx < rightIdx){
            int tempSum = numbers[leftIdx] + numbers[rightIdx];
            if (target == tempSum){
                res.push_back(leftIdx + 1);
                res.push_back(rightIdx + 1);
                break;
            }
            else if (target < tempSum){
                --rightIdx;
            }
            else{
                ++leftIdx;

            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> numbers = {{2,7,11,15}, {2,3,4}, {-1,0}};
    vector<int> targets = {9, 6, -1};

    for (int i = 0; i < (int)numbers.size(); ++i){
        vector<int> res = sol.twoSum(numbers[i], targets[i]);

        cout << "[" << res[0] << "," << res[1] << "]" << endl;
    }

    return 0;
}