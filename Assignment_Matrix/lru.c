#include<stdio.h>
int search(int lru[],int num)
{
    for(int i = 0;i < 4;i++)
    {
        if(num == lru[i])
        return i;
    }
    return -1;
}

int main()
{
    int lru[4] ={-1,-1,-1,-1};
    int arr[13] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int miss = 0;
    int count = 0;
    for(int i = 0;i < 13;i++)
    {
        if(search(lru,arr[i]) == -1)
        {
            miss++;
            if(count <= 3)
            {
                lru[count] = arr[i];
                count++;
            }
            else
            {
                for(int j = 0;j < 3;j++)
                lru[j] = lru[j+1];
                lru[3] = arr[i];
            }
        }
        else
        {
            int ind = search(lru,arr[i]);
            for(int j = ind;j < 3;j++)
            lru[j] = lru[j+1];
            lru[3] = arr[i];
        }
        printf("page miss");
        printf("%d",miss);
        printf("\n");
        for(int k = 0;k < 4;k++)
        {
            printf("%d ",lru[k]);
        }
            printf("\n");
    }

    printf("Miss");
    printf("%d",miss);
    return 0;
}

