#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st;
        
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int index = st.top();
                st.pop();
                answer[index] = i - index;
            }
            st.push(i);
        }
        
        return answer;
    }
};

int main(){
    Solution sol;
    vector<int> temp = {73,74,75,71,69,72,76,73};
    vector<int> res = sol.dailyTemperatures(temp);

    for (int i : res){
        cout << i << ",";
    }
    cout << endl;

    return 0;
}
