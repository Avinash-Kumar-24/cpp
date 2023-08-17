#include<bits/stdc++.h>
using namespace std;

void bubblesort(vector<int> &arr)
{
    bool flag = false;
    for(int i = 0;i < arr.size()-1;i++)
    {
        for(int j = 0;j<arr.size()-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j + 1]);
                flag = true;
            }
        }
        if(flag != true)
        break;
    }
}

int main()
{
    vector<int>arr = {4,5,2,1};

    bubblesort(arr);

    for(int i = 0;i<arr.size();i++)
    {
        cout << arr[i];
    }
    return 0;
}