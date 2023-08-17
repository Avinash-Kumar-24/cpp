#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int graph[5][5] =
    {
        {0, 9, 75, 0, 0},
        {9, 0, 95, 19, 42},
        {75, 95, 0, 51, 66},
        {0, 19, 51, 0, 31},
        {0, 42, 66, 31, 0}
    };

    bool selected[5];
    memset(selected,false,sizeof(selected));
    
    selected[0] = true;
    int edge = 0;
    while(edge < 4)
    {int x = 0;
    int min = 99999;
    int y = 0;
        for(int i = 0;i < 5;i++)
        {
            if(selected[i])
            {
                for(int j = 0;j < 5;j++)
                {
                    if(!selected[i]&& graph[i][j] != 0)
                    {
                        if(min > graph[i][j])
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << x << " - " << y << ":" << graph[x][y];
        cout << endl;
        selected[y] = true;
        edge++;
    }
    return 0;
}