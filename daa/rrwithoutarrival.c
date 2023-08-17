#include<stdio.h>

void rr(int burst[],int time)
{
    int store_burst[3];
    for(int i = 0;i < 3;i++)
    {
        store_burst[i] = burst[i];
    }
    int sum = 0;
    for(int i = 0;i < 3;i++)
    {
        sum = sum + burst[i];
    }
    int gnatt[20];
    gnatt[0] = 0;
    int j = 1;
    int check[3];
    while(sum > 0)
    {
        int i = 0;
        for(i = 0;i < 3;i++)
        {
            if(burst[i] > time)
            {
                gnatt[j] = gnatt[j-1] + time;
                sum = sum - time;
                burst[i] -= time;
                check[i] = j;
                j++;
            }
            else if(burst[i] > 0)
            {
                gnatt[j] = gnatt[j-1] + burst[i];
                sum -= burst[i];
                burst[i] = 0;
                check[i] = j;
                j++;
            }
        }
        
    }
    // for(int i = 0;i < j;i++)
    // {
    //     printf("%d",gnatt[i]);
    //     printf("\n");
    // }
    float Total_turnaround = 0;
    float Total_waiting = 0;
    for(int i = 0;i < 3;i++)
    {
        Total_turnaround += gnatt[check[i]];
    }
    for(int i = 0;i < 3;i++)
    {
        Total_waiting += gnatt[check[i]] - store_burst[i];
    }
    printf("The Avg Waiting:");
    printf("%f",Total_waiting/3);
    printf("The Avg turnaround:");
    printf("%f",Total_turnaround/3);
}

int main()
{
    int burst[3] = {30,6,8};
    // for(int i = 0;i < 3;i++)
    // {
    //     scanf("%d",&burst[i]);
    // }
    rr(burst,5);
    return 0;
}