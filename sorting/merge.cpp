#include<bits/stdc++.h>
using namespace std;

void merge_two_sorted_array(vector<int> &a1,int start,int mid,int last)
{
    vector<int>res;
    int i = start;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= last)
    {
        if(a1[i] < a1[j])
        {
            res[k++] = a1[i++];
        }
        else
        {
            res[k++] = a1[j++];
        }
    }
    while(i <= mid)
    {
        res[k++] = a1[i++];
    }
    while(j <= last)
    {
        res[k++] = a1[i++];
    }
}

int main()
{
    vector<int>a = {5,4,3,2,1};
    int start = 0;
    int mid = a.size()/2;
    int last = a.size()-1;
    merge_two_sorted_array(a,start,mid,last);
    for(int i =0;i<a.size();i++)
    {
        cout << a[i];
    }
    return 0;
}