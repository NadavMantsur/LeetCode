#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int bitsToReverse = 32;

        while (0 < bitsToReverse) {
            result <<= 1;
            // Set the least significant bit of result to the current bit of n
            result |= n & 1; 
            n >>= 1;
            --bitsToReverse;
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<uint32_t> inputs = {43261596, 4294967293};
    vector<uint32_t> expected = {964176192, 3221225471};

    for (uint32_t i = 0; i < inputs.size(); ++i){
        if (sol.reverseBits(inputs[i]) != expected[i]){
            cout << "wrong results for: " << i << endl;
        }
    }

    return 0;
}
