// the answer is to calc the time for each car to get target: t = dx / v
// sorting by positions will help to find the numbers of fleet

#include <iostream>
#include <vector>
#include <algorithm> //sort

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars; //pair<initial position, time>
        
        for (int i = 0; i < (int)position.size(); ++i) {
            cars.push_back({position[i], (double)(target - position[i]) 
                                                                / speed[i]});
        }
        
        // cout << "before sorting:" <<endl;
        // for (auto car : cars){
        //     cout << car.first << "," << car.second << " | " ;
        // }
        // cout << endl;

        sort(cars.begin(), cars.end(), greater<pair<int, double>>());  
        //sorting according to first element
        
        // cout << "after sorting:" <<endl;
        // for (auto car : cars){
        //     cout << car.first << "," << car.second << " | " ;
        // }
        // cout << endl;

        int fleets_cnt = 0;
        double currTime = -1.0;
        
        for (const auto& car : cars) {
            if (car.second > currTime) {
                currTime = car.second;
                ++fleets_cnt;
            }
        }
        
        return fleets_cnt;
    }
};

int main(){
    Solution sol;
    vector<int> target = {12, 10, 100};
    vector<vector<int>> position = {{10,8,0,5,3}, {3}, {0,2,4}};
    vector<vector<int>> speed = {{2,4,1,1,3}, {3}, {4,2,1}};
    vector<int> expected = {3, 1, 1};

    for (int i = 0; i < (int)target.size(); ++i){
        if (sol.carFleet(target[i], position[i], speed[i]) != expected[i]){
            cout << "failure in case:" << i << endl; 
        }
    }

    cout << "PASSED" << endl;

    return 0;
}