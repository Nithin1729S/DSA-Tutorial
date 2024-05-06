#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store suffixes and their indexes
struct Suffix {
    int index;
    string suffix;
};

// Comparator function to sort suffixes
bool suffixComparator(const Suffix &a, const Suffix &b) {
    return a.suffix < b.suffix;
}

// Function to build the suffix array
vector<int> buildSuffixArray(const string &text) {
    int n = text.length();
    vector<Suffix> suffixes(n);

    // Store suffixes and their indexes
    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].suffix = text.substr(i);
    }

    // Sort the suffixes
    sort(suffixes.begin(), suffixes.end(), suffixComparator);

    // Store the suffix array
    vector<int> suffixArray(n);
    for (int i = 0; i < n; i++)
        suffixArray[i] = suffixes[i].index;

    return suffixArray;
}

// Function to perform binary search on the suffix array
int search(const string &pattern, const string &text, const vector<int> &suffixArray) {
    int n = text.length();
    int m = pattern.length();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = pattern.compare(0, m, text, suffixArray[mid], m);

        if (cmp == 0) {
            return suffixArray[mid];
        } else if (cmp < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1; // Pattern not found
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern to search: ";
    getline(cin, pattern);

    vector<int> suffixArray = buildSuffixArray(text);

    int index = search(pattern, text, suffixArray);

    if (index != -1) {
        cout << "Pattern found at index: " << index << endl;
    } else {
        cout << "Pattern not found in the text." << endl;
    }

    return 0;
}
