#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> res;

    void backtrack(int n, int open, int close,string &temp) {
        if (open == n && close == n) {
            res.push_back(temp);
            return;
        }
        if (open < n) {
            temp += '(';
            backtrack(n, open + 1, close,temp);
            temp.pop_back();
        }
        if (close < open) {
            temp += ')';
            backtrack(n, open, close + 1,temp);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string temp;
        backtrack(n, 0, 0,temp);
        return res;
    }
};



int main() {
    Solution solution;

    
    int n = 1;
    vector<string> result = solution.generateParenthesis(n);

    
    cout << "Parentheses combinations for n=" << n << ":\n";
    for (const string& combination : result) {
        cout << combination << " ";
    }
    cout << "\n";

    return 0;
}
