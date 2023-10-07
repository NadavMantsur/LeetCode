#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> res;    

        // float tripple = num / 3;

        // if (0 == tripple % 10){
        //     if ((tripple - 1) + tripple + (tripple + 1) == num){
        //         res.push_back(tripple - 1);
        //         res.push_back(tripple);
        //         res.push_back(tripple + 1);
        //     }
        // }

        for (long long i = num / 3 - 1; i <= num / 3 + 1; ++i) {
            res.push_back(i);
        }

        if (res[0] + res[1] + res[2] == num) {
            return res;
        } 
        else {
            return {};
        }
    }
};

int main(){
    Solution sol;
    vector<long long> res = sol.sumOfThree(4);

    if (0 == res.size()){
        cout << "[]" << endl;
    }
    
    else{
        for (auto num : res){
            cout << num << ',';
        }
        cout << endl;
    }   

    return 0;
}