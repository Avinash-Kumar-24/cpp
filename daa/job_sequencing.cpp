/*     Write a code to solve Job sequencing with deadline Problem in O(n^2) time   */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class job
{
    public:
    int deadline,profit;
    job(int deadline,int profit)
    {
        this -> deadline = deadline;
        this -> profit = profit;
    }
};

bool compare(job* a,job* b)
{
    return a->profit > b -> profit;
}

int maxprofit(vector<job*>data)
{
    int res = 0;
    sort(data.begin(),data.end(),compare);
    int maxdeadline = 0;
    for(int i = 0;i < data.size();i++)
    {
        maxdeadline = max(maxdeadline,data[i]->deadline);
    }
    vector<int>r(maxdeadline,0);
    for(int i = 0;i < data.size();i++)
    {
        for(int j = data[i]->deadline -1;j >= 0;j--)
        {
            if(r[j] == 0)
            {
                r[j] = data[i] -> profit;
                res = res + data[i] -> profit;
                break;
            }
        }
    }
    return res;
}


int main()
{
    int j = 0;
    vector<job*>data;
    cout << "Enter the Number of jobs: ";
    cin >> j;
    for(int i = 0;i < j;i++)
    {
        int deadline,profit;
        cout << "Enter the deadline : ";
        cin >> deadline;
        cout << "Enter the profit : ";
        cin >> profit;
        job* a = new job(deadline,profit);
        data.push_back(a);
    }
    int res = maxprofit(data);
    cout << "The maximum profit is: " << res;
    return 0;
}


/*#########  Input 1 #########*/
/*
    Enter the Number of jobs: 5
    Enter the deadline : 2
    Enter the profit : 60
    Enter the deadline : 1
    Enter the profit : 100
    Enter the deadline : 3
    Enter the profit : 20
    Enter the deadline : 2
    Enter the profit : 40
    Enter the deadline : 1
    Enter the profit : 20

    ####### Output 1 #######
    
    The maximum profit is: 180

*/


/*#########  Input 2 #########*/

/*
    Enter the Number of jobs: 6
    Enter the deadline : 5
    Enter the profit : 200
    Enter the deadline : 3
    Enter the profit : 180
    Enter the deadline : 3
    Enter the profit : 190
    Enter the deadline : 2
    Enter the profit : 300
    Enter the deadline : 4   
    Enter the profit : 120
    Enter the deadline : 2
    Enter the profit : 10

    ###### Output 2 ########

    The maximum profit is: 990

*/