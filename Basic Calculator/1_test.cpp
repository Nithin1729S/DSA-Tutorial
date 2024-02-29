#include <iostream>
#include <stack>
#include <cctype>  // Include cctype for isdigit function
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

    int outStackPrecedence(char x)
    {
        if(x=='+' || x=='-') return 1;
        else if(x=='*' || x=='/') return 3;
        else if(x=='^') return 6;
        else if(x=='(') return 7;
        else return 0;
    }

    int inStackPrecedence(char x)
    {
        if(x=='+' || x=='-') return 2;
        else if(x=='*' || x=='/') return 4;
        else if(x=='^') return 5;
        else  return 0;
        //else if(x==')') return 0;
    }

    int isOperand(char x)
    {
        if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'||x=='('||x==')') return 0;
        return 1;
    }

    void infixToPostfix(string s)
    {
        postfix.clear();
        int i=0;
        while(s[i]!='\0')
        {
            if(isOperand(s[i]))
            {
                postfix+=s[i];
                i++;
            }
            else
            {
                if(stk.empty()||outStackPrecedence(s[i])>inStackPrecedence(stk.top()))
                {
                    stk.push(s[i]);
                    i++;
                }
                else if(outStackPrecedence(s[i])==inStackPrecedence(stk.top()))
                {
                    //char c=stk.top();
                    stk.pop();
                    i++;
                }
                else
                {
                    char c=stk.top();
                    stk.pop();
                    postfix+=c;
                }

            }
        }
        while(!stk.empty())
        {
            char c=stk.top();
            stk.pop();
            postfix+=c;
        }
        //postfix[i]='\0';
    }



    int calculate(string s) 
{
    s=trim(s);
    infixToPostfix(s);
    // cout << postfix;
    stack<int> stk1;

    for (int i = 0; i < postfix.length(); i++)  // Change to postfix.length()
    {
        if (isOperand(postfix[i]))
        {
            stk1.push(postfix[i] - '0');
        }
        else
        {
            int r;
            int x2 = stk1.top();
            stk1.pop();
            int x1 = stk1.top();
            stk1.pop();

            switch (postfix[i])
            {
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
            stk1.push(r);
        }
    }

    int v = stk1.top();
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

