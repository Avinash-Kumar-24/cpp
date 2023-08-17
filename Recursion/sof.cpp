#include<iostream>
using namespace std;

int sof(int n)
{
    if(n < 1)
    return 0;
    
    return sof(n-1) + n;
}
int main()
{
    int res = 0;
    res = sof(8);
    cout << res;
    return 0;
}