#include<iostream>
using namespace std;

void print(int num)
{
    if(num == 0)
    return;
    print(num-1);
    cout << num;
}
int main()
{
    print(5);
    return 0;
}