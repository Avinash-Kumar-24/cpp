#include<iostream>
using namespace std;
int partition(int arr[],int start,int end);
void qsort(int arr[],int start,int end)
{
    if(start < end)
    {
        int mid = partition(arr,start,end);
        qsort(arr,start,mid-1);
        qsort(arr,mid+1,end);
    }
}
int partition(int arr[],int start,int end)
{
    int pivot = arr[start];
    int i = start;
    int j = end;
    while(i < j)
    {
        while(arr[i] <= pivot && i <= end-1)
        {
            i++;
        }
        while(arr[j] > pivot && j >= start+1)
        {
            j--;
        }
        if(j > i)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j],arr[start]);
    return j;
}
int main()
{
    int arr[] = {1,9,5,6,4,3,8};
    qsort(arr,0,7);
    for(int i = 0;i < 7;i++)
    {
        cout << arr[i];
    }
    return 0;
}