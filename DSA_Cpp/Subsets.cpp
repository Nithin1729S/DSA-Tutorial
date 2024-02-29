#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    vector<vector<int>> ans;
    void PASS(vector<int>arr,int idx,vector<int>temp)
    {
        if(idx==arr.size())
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back(arr[idx]);
        PASS(arr,idx+1,temp);
        temp.pop_back();
        PASS(arr,idx+1,temp);
        
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {

        vector<int> temp;
        PASS(nums,0,temp);
        return ans;
        
    }
};


