#include <iostream>
using namespace std;
#include<vector>

/*This code will only work, when the arr[i]+arr[j]+arr[k]=key 
will be available in the arr,other wise it will be in infinite loop*/

vector<int> search(vector<int>arr,int key)
{
    vector<int>res;
    int start = 0;
    int end = arr.size() - 1;
    int mid = (arr.size() - 1) /2;

    while(start < end)
    {
        
        if(arr[end]+arr[end-1]+arr[end-2] < key)
        {
            break;
        }

        if(arr[start] + arr[mid] + arr[end] == key)
        {
            res.push_back(start);
            res.push_back(mid);
            res.push_back(end);
            break;
        }
        
        else if(arr[start] + arr[mid] + arr[end] > key)
        {
            if(end > mid+1)
            {
                end--;
            }
            else
            {
                mid--;
            }
        }
        
        else
        {
            if(start+1 < mid)
            {
                start++;
            }
            else
            {
                mid++;
            }
        }
    }
    return res;
}

int main()
{
    vector<int>res;

    vector<int>arr = {23,34,56,67,78,100,150,250};
    int key = 423;
    res = search(arr,key);

    for(int i = 0;i < res.size();i++)
    {
        cout << res[i];
    }
    return 0;
}