#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> ans;

    void backtrack(string& s, int idx) {
        if (idx == s.size()) {
            ans.push_back(s);
            return;
        }

        if (s[idx] >= 'a' && s[idx] <= 'z')
        
        {
            s[idx] = toupper(s[idx]);
            backtrack(s, idx + 1);
            s[idx] = tolower(s[idx]);
        } 
        
        else if (s[idx] >= 'A' && s[idx] <= 'Z') 
        {
            s[idx] = tolower(s[idx]);
            backtrack(s, idx + 1);
            s[idx] = toupper(s[idx]);
        }


        backtrack(s, idx + 1);  //for digits
    }

    vector<string> letterCasePermutation(string s) {
        backtrack(s, 0);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> result = solution.letterCasePermutation("a1b2");
    
    // Print the result
    for (const string& str : result) {
        cout << str << " ";
    }

    return 0;
}
