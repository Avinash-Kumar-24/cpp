#include<iostream>
using namespace std;

void reverse(int start,int end,int arr[])
{
    if(start >= end)
    return;
    swap(arr[start],arr[end]);
    reverse(start+1,end-1,arr);
}

int main()
{
    int arr[] = {1,2,5,8,9};
    reverse(0,4,arr);
    for(int i = 0;i < 5;i++)
    {
        cout << arr[i];
    }
    return 0;
}