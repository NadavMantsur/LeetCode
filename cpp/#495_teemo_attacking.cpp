#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (0 == duration){
            return 0;
        }

        int totalTime = 0;

        for (int i = 0; i < (int)timeSeries.size() -1; ++i){
            if (timeSeries[i] + duration < timeSeries[i + 1]){
                totalTime += duration;
            }
            else{
                totalTime += (timeSeries[i + 1] - timeSeries[i]);
            }
        }
        // returns totalTime + the last attack calculation
        return totalTime + duration;
    }

    // chatGPT
    // int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    //     if (timeSeries.empty()) {
    //         return 0;
    //     }

    //     int totalDuration = 0;
    //     for (int i = 1; i < (int)timeSeries.size(); ++i) {
    //         int poisonDuration = min(duration, timeSeries[i] - timeSeries[i - 1]);
    //         totalDuration += poisonDuration;
    //     }

    //     // Add the duration of the last poison effect
    //     totalDuration += duration;

    //     return totalDuration;
    // }
};

int main(){
    Solution sol;
    vector<vector<int>> timeSerieses = {{1,4}, {1,2}, {1,2,3,4,5,6,7,8,9}};
    vector<int> durations = {2, 2, 0};
    vector<int> expected = {4,3, 0};

    for (int i = 0; i < (int)timeSerieses.size(); ++i){
        if (sol.findPoisonedDuration(timeSerieses[i], durations[i]) == expected[i]){
            cout << "Passed" << endl;
        }
        else{
         cout<< "Failed" << endl;
        }
    }

    return 0;
}