#include<iostream>
#include<vector>
using namespace std;

int fibo(int n,vector<int>&dp)
{
    if(n == 0)
    return 0;
    if(n == 1)
    return 1;
    for(int i = 2;i <= n;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[dp.size()-1];
}

int main()
{
    int n;
    cout << "Enter the value of n:";
    cin >> n;
    vector<int>dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    int res = fibo(n,dp);
    cout << res;
    return 0;
}