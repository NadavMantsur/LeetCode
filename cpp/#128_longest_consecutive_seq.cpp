#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end());

        int longestSeq = 0;

        for (int num : nums){
            if (numsSet.find(num - 1) == numsSet.end()){
                int currSeq = 1;

                while (numsSet.find(num + 1) != numsSet.end()){
                    ++currSeq;
                    num += 1;
                }

                longestSeq = max(longestSeq, currSeq);
            }
        }

        return longestSeq;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {100,4,200,1,3,2};

    cout << sol.longestConsecutive(nums) << endl;

    return 0;
}