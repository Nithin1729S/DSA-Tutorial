#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int factorial(int n,vector<int>&dp)
{
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=n*factorial(n-1,dp);
}
int main()
{
    int n=25;
    vector<int>dp(n+1,-1);
    cout<<factorial(25,dp);
    return 0;
    

}