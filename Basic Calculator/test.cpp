#include <iostream>
#include <stack>
#include <climits>  // Include for INT_MAX and INT_MIN
#include <cctype>   // Include cctype for isspace function
#include <sstream>  // Include for stringstream
#include <string>

using namespace std;

class Solution {
public:
    stack<char> stk;
    string postfix;

    string trim(string s) {
        string str;
        for (auto i : s) {
            if (i != ' ') {
                str += i;
            }
        }
        return str;
    }

    int outStackPrecedence(char x) {
        if (x == '+' || x == '-') return 1;
        else if (x == '*' || x == '/') return 3;
        else if (x == '^') return 6;
        else if (x == '(') return 7;
        else return 0;
    }

    int inStackPrecedence(char x) {
        if (x == '+' || x == '-') return 2;
        else if (x == '*' || x == '/') return 4;
        else if (x == '^') return 5;
        else return 0;
    }

    int isOperand(char x) {
        if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')') return 0;
        return 1;
    }

    void infixToPostfix(string s) {
        postfix.clear();
        int i = 0;
        while (s[i] != '\0') {
            if (isOperand(s[i])) {
                postfix += s[i];
                i++;
            } else {
                if (stk.empty() || outStackPrecedence(s[i]) > inStackPrecedence(stk.top())) {
                    stk.push(s[i]);
                    i++;
                } else if (outStackPrecedence(s[i]) == inStackPrecedence(stk.top())) {
                    // char c = stk.top();
                    stk.pop();
                    i++;
                } else {
                    char c = stk.top();
                    stk.pop();
                    postfix += c;
                }
            }
        }
        while (!stk.empty()) {
            char c = stk.top();
            stk.pop();
            postfix += c;
        }
    }

    int calculate(string s) {
        s = trim(s);
        infixToPostfix(s);
        stack<long long> stk1;  // Use long long to handle large numbers

        for (int i = 0; i < postfix.length(); i++) {
            if (isOperand(postfix[i])) {
                string operand;
                while (i < postfix.length() && isOperand(postfix[i])) {
                    operand += postfix[i++];
                }

                if (!operand.empty()) {
                    stringstream ss(operand);
                    long long num;
                    if (!(ss >> num)) {
                        // Handle conversion error
                        return 0;  // You can choose an appropriate error value
                    }
                    stk1.push(num);
                }
            } else {
                long long r;
                long long x2 = stk1.top();
                stk1.pop();
                long long x1 = stk1.top();
                stk1.pop();

                switch (postfix[i]) {
                    case '+':
                        r = x1 + x2;
                        break;
                    case '-':
                        r = x1 - x2;
                        break;
                    case '*':
                        r = x1 * x2;
                        break;
                    case '/':
                        r = x1 / x2;
                        break;
                }

                // Check for overflow
                if (r > INT_MAX) {
                    return INT_MAX;
                } else if (r < INT_MIN) {
                    return INT_MIN;
                }

                stk1.push(r);
            }
        }

        int v = static_cast<int>(stk1.top());
        stk1.pop();
        return v;
    }
};

int main() {
    Solution sol;
    string inputExpression = "2147483647";
    int result = sol.calculate(inputExpression);
    cout << "Result: " << result << endl;
    return 0;
}
