#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<string>res;

    void backtrack(int k,string temp)
    {
        if(k==0)
        {
            res.push_back(temp);
            return;
        }
        temp+='0';
        backtrack(k-1,temp);
        temp.pop_back();
        temp+='1';
        backtrack(k-1,temp);
        temp.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) 
    {
        
        
    }
    vector<string> binaryStrings()
    {
        string temp;
        backtrack(2,temp);
        return res;
    }
};


int main()
{
    Solution sol;
    vector<string>res=sol.binaryStrings();
    for(auto i:res) cout<<i<<endl;
}