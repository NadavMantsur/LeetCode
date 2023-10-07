#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>    // reverse

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Count the frequency of each element.
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            ++freqMap[num];
        }

        // Create a min-heap (priority queue) based on frequency.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        // element type, the elements container of the pqueue, compare function

        // Iterate through the frequency map and add elements to the min-heap.
        for (const auto& entry : freqMap) {
            minHeap.push({entry.second, entry.first});
            if ((int)minHeap.size() > k) {
                minHeap.pop(); // Maintain only the top K elements in the min-heap.
            }
        }

        // Step 4: Extract the top K frequent elements from the min-heap.
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        //  You may return the answer in any order. but:
        // Reverse the result vector to get the elements in descending order of frequency.
        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> topKFrequentElements = sol.topKFrequent(nums, k);

    // Print the top K frequent elements.
    for (int num : topKFrequentElements) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
