#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (0 != b) {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};


int main(){
    Solution sol;

    cout << sol.getSum(1, 3) << endl;

    return 0;
}