#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& arr, int idx) {
        if (idx == arr.size()) {
            ans.push_back(arr);
            return;
        }
        for (int j = idx; j < arr.size(); j++) {
            swap(arr[idx], arr[j]);
            backtrack(arr, idx + 1);
            swap(arr[idx], arr[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};

int main() {
    vector<int> arr = {1, 2, 3}; // Initialize arr with your desired values
    Solution solution;
    vector<vector<int>> result = solution.permute(arr);

    // Print the result if needed
    for (const auto& vec : result) {
        cout << "[ ";
        for (const int& num : vec) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
