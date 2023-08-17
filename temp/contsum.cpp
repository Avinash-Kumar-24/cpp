#include<bits/stdc++.h>
using namespace std;

int largestContiguousSum(vector <int> &arr)
{
    vector<int>res;
	int i = 0;
	int j = 0;
	for(i = 0;i < arr.size();i++)
	{
		if(arr[i] > 0)
		{
			res[j] += arr[i];
		}
		else 
		{
			i++;
			j++;
			res[j] += arr[i];
		}
	}
	
	int largeno = res[0];
	for(int k = 1;k < res.size();k++)
	{
		if(largeno < res[k])
		{
			largeno = res[k];
		}
	}
	
	return largeno;
}

int main()
{
    int* a;
    int size;
    a = new int[size];
    int i = 0;
    cout << "Give size of array:";
    cin >> size;
    while(i < size)
    {
        cout << "Enter the element in array:";
        cin >> a[i];
        i++;
    }
    int res = largestContiguousSum(a);
    cout << res;
    return 0;
}