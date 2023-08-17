#include<iostream>
#include<vector>
using namespace std;

bool palindrome(int start,string str)
{
    if(start >= str.size())
    return true;
    if(str[start] != str[str.size()-1 -start])
    return false;
    return palindrome(start+1,str);

}

int main()
{
    string str = {"amadama"};
    cout << palindrome(0,str);
    return 0;
}