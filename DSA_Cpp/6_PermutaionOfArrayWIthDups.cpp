#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& arr, int idx) {
        if (idx == arr.size()) {
            ans.push_back(arr);
            return;
        }

        unordered_set<int> used;  // To track used elements at each level of recursion

        for (int j = idx; j < arr.size(); j++) {
            if (used.find(arr[j]) == used.end()) {
                swap(arr[j], arr[idx]);
                backtrack(arr, idx + 1);
                swap(arr[j], arr[idx]);

                // Mark the current element as used to avoid duplicates
                used.insert(arr[j]);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Test with a vector of integers
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result = solution.permuteUnique(nums);

    // Print the result
    cout << "Unique Permutations:" << endl;
    for (const vector<int>& permutation : result) {
        cout << "[ ";
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
