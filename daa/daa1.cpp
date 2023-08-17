    /*Given an array. Let us assume that there can be duplicates in the list.
        Write a Program to search for an element in the list in such a way 
            that we get the highest index if there are duplicates.*/

#include<iostream>
#include<map>
#include<vector>
using namespace std;

// int search(vector<int>arr,int key)
// {
//     int i = arr.size() - 1;
//     while(i >= 0)
//     {
//         if(arr[i] == key)
//         {
//             return i;
//         }
//         else
//         {
//             i--;
//         }
//     }
//     return i;
// }

int search(vector<int>arr,int key)
{
    int i = 0;
    int j = arr.size() - 1;
    int count = 0;
    while(i < j)
    {
        if(arr[j] == key)
        {
            return j + 1;
        }
        if(arr[i] == key)
        {
            count = i;
            i++;
        }
        else if(arr[j] != key && arr[i] != key)
        {
            j--;
            i++;
        }
    }
    if(count > 0)
    {
        return count + 1;
    }
    return 0;
}
int main()
{
    vector<int>arr={1,5,8,6,9,1,4,1,5,6};
    int key = 2;
    int res = search(arr,key);
    if(res == 0)
    {
        cout << "Key Not Available";
    }
    else
    {
        cout << "The index start from 1 " << endl;
        cout << "The last index of " << key <<" is: " << res;
    }
    return 0;
}

/*
    #Input1
        vector<int>arr={1,5,8,6,9,1,4,1,8,6};
        int key = 5;
    #Output1
        The index start from 1 
        The last index of 5 is: 2
    #Input2
        vector<int>arr={1,5,8,6,9,1,4,1,5,6};
        int key = 5;
    #Output2
        The index start from 1 
        The last index of 5 is: 9
    #Input3
        vector<int>arr={1,5,8,6,9,1,4,1,5,6};
        int key = 2;
    #Output3
        Key Not Available
*/