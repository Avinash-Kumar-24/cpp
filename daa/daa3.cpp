            /*Given key in a sorted array A with distinct values. Write a
            program to find i,j,k such that A[i] + A[j] + A[K] == key.*/

#include<iostream>
using namespace std;
#include<vector>

vector<int> search(vector<int>arr,int key)
{
    vector<int>res;
    for(int i = 0;i < arr.size();i++)
    {
        int sp = i + 1;
        int lp = arr.size()-1;
        while(sp < lp)
        {
            if(arr[i]+arr[sp]+arr[lp] == key)
            {
                res.push_back(i);
                res.push_back(sp);
                res.push_back(lp);
                return res;    
            }
            else if(arr[i]+arr[sp]+arr[lp]>key)
            {
                lp--;
            }
            else
            {
                sp++;
            }
        }
    }
    return res;
}

int main()
{
    vector<int>res;

    vector<int>arr = {1,2,4,4,4,6,7,8,9,10,11,12,15,55,105};
    int key = 161;
    res = search(arr,key);

    if(res.size() == 0)
    {
        cout <<"No Combination Available";
    }
    else
    {
        cout <<"ith index -> " <<res[0] << endl;
        cout <<"jth index -> " <<res[1] << endl;
        cout <<"kth index -> " <<res[2] << endl;
    }
    return 0;
}

/*

    #Input1
        vector<int>arr = {1,2,4,4,4,6,7,8,9,10,11,12,15,55,105};
        int key = 161;
    #Output1
        ith index -> 0
        jth index -> 13
        kth index -> 14
    #Input2
        vector<int>arr = {1,2,4,4,4,6,7,8,9,10,11,12,15,55,106};
        int key = 161;
    #Output2
        No Combination Available

*/