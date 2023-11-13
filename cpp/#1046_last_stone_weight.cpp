#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        for (auto stone : stones){
            maxHeap.push(stone);
        }

        while (1 < maxHeap.size()){
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();

            int res = smash(y, x);

            if (0 != res){
                maxHeap.push(res);
            }

            // printQueue(maxHeap);
        }

        if (0 != maxHeap.size()){
            return maxHeap.top();
        }

        return 0;
    }

private:
    priority_queue<int, vector<int>, less<int>> maxHeap;

    int smash(int y, int x){
        return y - x;
    }

    // void printQueue(priority_queue<int, vector<int>, less<int>> maxHeap){
    //     while (!maxHeap.empty()) {
    //         cout << maxHeap.top() << " ";
    //         maxHeap.pop();
    //     }
    //     cout << endl;
    // }
};

int main(){
    Solution sol;

    vector<int> stones = {2,7,4,1,8,1};

    cout << sol.lastStoneWeight(stones) << endl;

    return 0;
}