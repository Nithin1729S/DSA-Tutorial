#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> kmp(string text, string pattern) {
    string concat = pattern + '#' + text;
    vector<int> pi = prefix_function(concat);
    vector<int> matches;
    int patternLength = pattern.length();
    for (int i = patternLength + 1; i < pi.size(); i++) {
        if (pi[i] == patternLength)
            matches.push_back(i - 2 * patternLength);
    }
    return matches;
}

int main() {
    string text = "ABCABCABCABCABC";
    string pattern = "ABC";
    vector<int> matches = kmp(text, pattern);
    if (matches.empty())
        cout << "Pattern not found in the text." << endl;
    else {
        cout << "Pattern found at positions: ";
        for (int pos : matches)
            cout << pos << " ";
        cout << endl;
    }
    return 0;
}
