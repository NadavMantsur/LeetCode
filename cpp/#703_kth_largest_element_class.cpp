#include <queue>
#include <vector>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if (minHeap.size() < kth) {
            minHeap.push(val);
        } 
        else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        
        return minHeap.top();
    }

private:
    int kth;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
