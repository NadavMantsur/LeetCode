// 20. Valid Parentheses

#include <iostream>
#include <string>
#include <stack>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> stack;

        for (char ch : s)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                stack.push(ch);
            }
            else
            {
                if (stack.empty())
                {
                    return false; // Unmatched closing bracket
                }

                char top = stack.top();
                stack.pop();

                if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '['))
                {
                    return false; // Mismatched brackets
                }
            }
        }

        return stack.empty(); // If the stack is empty, all brackets are matched
    }
};

int main()
{
    Solution solution;
    std::string input;

    std::cout << "Enter a string with brackets: ";
    std::cin >> input;

    if (solution.isValid(input))
    {
        std::cout << "The input string is valid." << std::endl;
    }
    else
    {
        std::cout << "The input string is not valid." << std::endl;
    }

    return 0;
}
