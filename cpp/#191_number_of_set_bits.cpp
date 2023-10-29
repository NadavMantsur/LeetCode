#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;

        for (int i = 0; i < 32; ++i){
            cnt += n & 1;
            n >>= 1;
        }

        return cnt;
    }
};

int main(){
    Solution sol;

    cout << sol.hammingWeight(11) << endl; // 3

    return 0;
}

// Hamming weight represents the number of '1' bits in a binary representation 
// of a number,