#include<bits/stdc++.h>
using namespace std;
vector<int> rabin_karp(const std::string& s, const std::string& t) {
    const int p = 31; // Prime number
    const int m = 1e9 + 9; // Modulo value

    int S = s.size(), T = t.size();

    // Precompute powers of p
    std::vector<long long> p_pow(std::max(S, T));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++) {
        p_pow[i] = (p_pow[i - 1] * p) % m;
    }

    // Calculate hash values for text t
    std::vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++) {
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    }

    // Calculate hash value for pattern s
    long long h_s = 0;
    for (int i = 0; i < S; i++) {
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }

    // Store occurrences of pattern s in text t
    std::vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i + S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m) {
            occurrences.push_back(i);
        }
    }

    return occurrences;
}

int main() {
    string pattern, text;

    // Input pattern
    cout << "Enter pattern: ";
    cin >> pattern;

    // Input text
    cout << "Enter text: ";
    cin >> text;

    // Call the Rabin-Karp function
    std::vector<int> occurrences = rabin_karp(pattern, text);

    // Output results
    if (occurrences.empty()) {
        cout << "Pattern not found in the text.\n";
    } else {
        cout << "Pattern found at positions: ";
        for (int pos : occurrences) {
            std::cout << pos << " ";
        }
        std::cout << std::endl;
    }

}