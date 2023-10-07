#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // time comp: O(n),     space comp: O(n)
    // vector<int> productExceptSelf(vector<int>& nums) {
    //     int n = nums.size();
        
    //     vector<int> leftProducts(n);
    //     vector<int> rightProducts(n);
    //     vector<int> result(n);
        
    //     int leftProduct = 1;
    //     for (int i = 0; i < n; ++i) {
    //         leftProducts[i] = leftProduct;
    //         leftProduct *= nums[i];
    //     }
        
    //     int rightProduct = 1;
    //     for (int i = n - 1; i >= 0; --i) {
    //         rightProducts[i] = rightProduct;
    //         rightProduct *= nums[i];
    //     }
        
    //     for (int i = 0; i < n; i++) {
    //         result[i] = leftProducts[i] * rightProducts[i];
    //     }
        
    //     return result;
    // }

     // time comp: O(n),     space comp: O(1)
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n, 1); // Initialize the result array with 1s.

        int prefixProduct = 1;
        int suffixProduct = 1;

        // Calculate prefix products
        for (int i = 0; i < n; ++i) {
            result[i] *= prefixProduct;
            prefixProduct *= nums[i];
        }

        cout << "result after prefix ";
        for (auto num : result){
            cout << num << ",";
        }
        cout << endl;

        // Calculate suffix products and update the result array.
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= suffixProduct;
            suffixProduct *= nums[i];
        }

        cout << "result after suffix ";
        for (auto num : result){
            cout << num << ",";
        }
        cout << endl;

        return result;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,8,10,2,5};
    vector<int> result = sol.productExceptSelf(nums);

    for (auto num : result){
        cout << num << ",";
    }
    cout << endl;

    return 0;
}
