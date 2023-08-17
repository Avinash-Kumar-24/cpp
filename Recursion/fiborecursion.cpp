#include<iostream>
#include<vector>
using namespace std;

int fibo(int n, vector<int>&dp)
{
    if(n == 0)
    return 0;
    if(n == 1)
    return 1;

    if(dp[n] != -1)
    return dp[n];
    return dp[n] = fibo(n-1,dp) + fibo(n-2,dp);
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