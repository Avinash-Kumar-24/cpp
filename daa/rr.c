#include<stdio.h>

void rr(int burst[],int arrival[],int time)
{
    int gnatt[20];
    gnatt[0] = 0;
    // gnatt[1] = 3;
    int sum = 32;
    int j = 1;
    while(sum > 0)
    {
        int i = 0;
        int temp = gnatt[j-1];
        sum -= gnatt[j-1];
        if(temp <= 6)
        {
            for(i = 0;i <= temp;i++)
            {
                if(burst[i] > time)
                {
                    printf("%d ",burst[i]);
                    gnatt[j] = gnatt[j-1] + time;
                    sum -= time; 
                    burst[i] -= time;
                    // printf("%d %d",gnatt[j],sum);
                    j++;
                    
                }
                else if(burst[i] != 0)
                {printf("%d ",burst[i]);
                    gnatt[j] = gnatt[j-1] + burst[i];
                    sum -= burst[i];
                    burst[i] = 0;
                    // printf("%d",gnatt[j]);
                    j++;
                }
            }
        }
        else
        {
            for(i = 0;i <= 6;i++)
            {
                if(burst[i] > time)
                {printf("%d ",burst[i]);
                    gnatt[j] = gnatt[j-1] + time;
                    sum -= time; 
                    burst[i] -= time;
                    // printf("%d",gnatt[j]);
                    j++;
                }
                else if(burst[i] != 0)
                {printf("%d ",burst[i]);
                    gnatt[j] = gnatt[j-1] + burst[i];
                    sum -= burst[i];
                    burst[i] -= burst[i] ;
                    // printf("%d",gnatt[j]);
                    j++;
                }
            }
        }
    }
    printf("The gnatt");
    for(int i = 0;i < j;i++)
    {
        printf("%d",gnatt[i]);
        printf("\n");
    }
}
int main()
{
    int burst[6] = {5,6,7,9,2,3};
    int arrival[6] = {5,4,3,0,2,6};
    int time = 3;
    rr(burst,arrival,time);
    return 0;
}