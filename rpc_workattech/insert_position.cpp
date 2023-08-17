#include<bits/stdc++.h>
using namespace std;

int getInsertPosition(vector<int> &arr, int key)
{
    // add your logic here
	for(int i =0;i< arr.size();i++)
	{
		if(key <= arr[i])
		{
			return i;
		}
		else if(key > arr[arr.size() - 1])
			return arr.size();
	}
}

int main()
{
    vector<int>a;
    for(int i = 0;i < 5;i++)
    {
        int n;
        cin >> n;
        a.push_back(n);
    }
    int s = getInsertPosition(a,2);
    cout << "The position is:" << s;
    return 0;
}