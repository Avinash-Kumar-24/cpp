            /*Write a program for finding i and j in an array 
            'A' for any key such that A[j]^2 + A[i]^2 == key*/

#include<math.h>
#include<iostream>
#include<map>
#include<vector>
using namespace std;

pair<int,int> search(vector<int>arr,int key)
{
    pair<int,int>res;
    map<int,int>mp;
    for(int i = 0;i < arr.size();i++)
    {
        mp[arr[i]*arr[i]] = i;
    }

    for(int i = 0;i < arr.size();i++)
    {
        auto it = mp.find(key - (arr[i]*arr[i]));
        if(it != mp.end())
        {
            res.first = i + 1;
            res.second = mp[key - (arr[i]*arr[i])] + 1;
            break;
        }
    }
    return res;
}
int main()
{
    vector<int>arr = {1,5,4,9,23,24};
    pair<int,int>res;
    res = search(arr,650);
    if(res.first == 0 && res.second == 0)
    {
        cout << "No Combination Available";
    }
    else
    {
        cout << "Index starts from 1" << endl;
        cout << "Index i is : " <<res.first << endl <<"Index j is : " << res.second;
    }
    
    return 0;
}

/*
    #Input1
        vector<int>arr = {1,2,3,4,5,6};
        int key = 25;
    #Output1
        Index starts from 1
        Index i is : 3
        Index j is : 4
    #Input2
        vector<int>arr = {1,5,4,9,25,24};
        int key = 650;
    #Output2
        Index starts from 1
        Index i is : 2
        Index j is : 5
    #Input3
        vector<int>arr = {1,5,4,9,23,24};
        int key = 650;
    #Output3
        No Combination Available
*/