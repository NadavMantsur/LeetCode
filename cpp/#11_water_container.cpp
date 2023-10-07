#include <vector>
#include <iostream>
#include <algorithm> //min, max

using namespace std;

class Solution {
public:
    //O(n^2)
    // int maxArea(vector<int>& height) {
    //     int res = 0;

    //     for (size_t i = 0; i < height.size() - 1; ++i){
    //         for (size_t j = i + 1; j < height.size(); ++j){
    //             res = max(res, int(min(height[i], height[j]) * (j - i)));
    //         }
    //     }

    //     return res;
    // }

    // O(n) solution using two-pointer approach
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int h = min(height[left], height[right]);
            maxArea = max(maxArea, h * (right - left));
            if (height[left] < height[right]) {
                ++left;
            } 
            else {
                --right;
            }
        }

        return maxArea;
    }

};

int main(){
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout << sol.maxArea(height) << endl;

    return 0;
}