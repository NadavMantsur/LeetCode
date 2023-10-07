#include <iostream>
#include <vector>
#include <algorithm> // binary_search

using namespace std;


class Solution {
public:
    // time: O(log(m * n))
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (0 == m) {
            return false;
        }

        int n = matrix[0].size();
        
        int left = 0;
        int right = m * n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midElement = matrix[mid / n][mid % n]; 

            if (target == midElement) {
                return true;
            }
            else if (target > midElement) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return false;
    }
};


int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}}; 

    cout << sol.searchMatrix(matrix, 3) << endl;
    cout << sol.searchMatrix(matrix, 13) << endl;

    return 0;
}