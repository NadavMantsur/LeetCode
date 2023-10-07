// The expression 3 − 4 + 5 in conventional notation is 3 4 − 5 + in reverse 
// Polish notation

#include <iostream>
#include <string> //stoi
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;

        for (auto token : tokens){
            if (!isOperator(token)){
                nums.push(stoi(token));
            }
            else{
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();

                nums.push(calculator(num1, num2, token));
            }
        }

        return nums.top();
    }

private:
    bool isOperator(string& str){
        if (("+" == str) || ("-" == str) || ("*" == str) || ("/" == str)){
            return true;
        }

        return false;
    }

    int calculator(int num1, int num2, const string& operation) {
        int result;
        
        switch(operation[0]) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    // Handle division by zero error
                    cerr << "Error: Division by zero is not allowed." << endl;
                    result = 0; 
                }
                break;
            default:
                // Handle an unknown operator
                cerr << "Error: Unknown operator '" << operation << "'." << endl;
                result = 0;
                break;
        }
        
        return result;
    }
};


int main(){
    Solution sol;
    vector<string> tokens = {"2","1","+","3","*"};
    cout << sol.evalRPN(tokens) << endl;
    return 0;
}