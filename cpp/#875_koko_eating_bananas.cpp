#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1; // Minimum possible speed
        int right = maxElement(piles);

        // the binary search is on the possible values of k (left): 1 - maxElement
        while (left < right) {
            // mid ==> k
            int mid = left + (right - left) / 2;
            int hours = 0;
            
            // Calculate total hours required at current speed
            for (int pile : piles) {
                hours += (pile + mid - 1) / mid; // Ceil division (rounded up)
            }
            
            // Adjust the search range
            if (hours > h) {
                left = mid + 1;
            } 
            else {
                right = mid;
            }
        }
        
        return left; // Minimum speed required to eat all bananas within h hours
    }

private:
    int maxElement(vector<int>& piles){
        int maxPile = 0;

        for (auto pile : piles){
            maxPile = max(pile, maxPile);
        }

        return maxPile;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> piles = {{3,6,7,11}, {30,11,23,4,20}, {30,11,23,4,20}};
    vector<int> hours = {8,5,6};
    vector<int> expected = {4,30,23};

    for (int i = 0; i < (int)piles.size(); ++i){
        if (sol.minEatingSpeed(piles[i], hours[i]) != expected[i]){
            cout << "failure" << endl;
        }
    }

    return 0;
}