#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int key) 
{
    // add your logic here
	for(int i = 0;i< matrix.size();i++)
	{
		for(int j = 0;j< matrix[0].size();j++)
		{
			if(matrix[i][j] == key )
			{
				return true;
				break;
			}
		}
	}
	return false;
}
