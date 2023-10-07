#include <iostream>
#include <vector>

class Solution {
public:
    bool isOneBitCharacter(std::vector<int>& bits) {
        int i = 0;
        while (i < bits.size() - 1) {
            if (0 == bits[i]) {
                ++i; // Move one step for a one-bit character
            } 
            else {
                i += 2; // Skip the next bit for a two-bit character
            }
        }
        return i == bits.size() - 1;
    }
};

int main() {
    Solution solution;

    std::vector<int> bits1 = {1, 0, 0};
    std::cout << "bits1: " << solution.isOneBitCharacter(bits1) << std::endl; // Output:  true

    std::vector<int> bits2 = {1, 1, 1, 0};
    std::cout << "bits2: " << solution.isOneBitCharacter(bits2) << std::endl; // Output:  false

    return 0;
}


// explenation:
// iterate through the bits array while keeping track of the current position. 
// If you encounter a '0', it means you have found a one-bit character. 
// If you encounter '1', it means you have found a two-bit character, and you 
// should skip the next bit because it's part of that two-bit character. 
// If you reach the end of the array and haven't encountered a '1' that you 
// skipped, then the last character is a one-bit character.