#include <iostream>
#include <vector>

using namespace std;

// time complexity: O(nlogn)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res; // = vector<int> res(n + 1, 0);

        for (int i = 0; i <= n; ++i){
            res.push_back(countSetBits(i));
        }

        return res;
    }

    // time complexity: O(n)
    // To calculate the number of set bits for i,
    // use the value for i >> 1 and add 1 if i is odd.
    // vector<int> countBits(int n) {
    //     vector<int> res(n + 1, 0);

    //     for (int i = 1; i <= n; ++i){
    //         res[i] = res[i >> 1] + (i & 1);
    //     }

    //     return res;
    // }

private:
    int countSetBits(int num){
        int cnt = 0;

        while (0 != num){
            cnt += num & 1;
            num  = num >> 1;
        }

        return cnt;
    }
};

// the time complexity of this solution is O(n * m), where n is the input value 
// n and m is the average number of set bits in the binary representation of 
// numbers from 0 to n. In the worst case, m can be approximately equal to the 
// number of bits in n, which is O(log2(n)).

void printVector(vector<int> vec){
    for (auto num : vec){
        cout << num << " ";
    }
}

int main(){
    Solution sol;
    vector<int> inputs = {2, 5};
    
    for (int i = 0; i < (int)inputs.size(); ++i){
        vector<int> res = sol.countBits(inputs[i]);

        cout << "vector " << i << ": ";
        printVector(res);
        cout << endl;
    }

    return 0;
}