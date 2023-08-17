#include<stdio.h>

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int arr[],int arr1[], int low, int high)
{
	int pivot = arr[high];
	
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		
		if (arr[j] < pivot) 
        {
			
			i++;
			swap(&arr[i], &arr[j]);
            swap(&arr1[i], &arr1[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
    swap(&arr1[i + 1], &arr1[high]);
	return (i + 1);
}

void quickSort(int arr[],int arr1[],int low, int high)
{
	if (low < high) 
    {
		
		int pi = partition(arr,arr1, low, high);
		
		quickSort(arr,arr1, low, pi - 1);
		quickSort(arr,arr1, pi + 1, high);
	}
}


void sjf(int burst[],int arrival[])
{
    int gnatt[6];
    gnatt[0] = 0;
    quickSort(arrival,burst,0,4);
    gnatt[1] = burst[0];
    int check[5] = {0,-1,-1,-1,-1};
    int k = 0;
    for(int i = 2;i < 6;i++)
    {
        int j = 0;
        int min = 9999;
        while(arrival[j] < gnatt[i-1])
        {
            if(burst[j] < min && check[j] == -1)
            {
                k = j;
                min = burst[j];
            }
            j++;
        }
        check[k] = i-1;
        gnatt[i] = gnatt[i-1] + min;
    }
    for(int i = 0;i < 6;i++)
    {
        printf("%d",gnatt[i]);
        printf("\n");
    }
    float Total_waiting_time = 0;
    float Total_turnaround_time = 0;
    for(int i = 1;i < 6;i++)
    {
        // printf("%d",arrival[check[i-1]]);
        Total_turnaround_time += (gnatt[i] -arrival[check[i-1]]);
        Total_waiting_time += (gnatt[i-1] - arrival[check[i-1]]);
        // printf("%d",Total_turnaround_time);
    }
    printf("%f",Total_turnaround_time/5);
        printf("\n");
    printf("%f",Total_waiting_time/5);
}
int main()
{
    int burst[5],arrival[5];
    printf("Enter the values:");
    for(int i = 0;i < 5;i++)
    {
        scanf("%d",&burst[i]);
        scanf("%d",&arrival[i]);
    }
    sjf(burst,arrival);
    return 0;
}