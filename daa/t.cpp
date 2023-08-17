#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Task {
public:
    int deadline, profit;
    Task(int deadline, int profit) {
        this->deadline = deadline;
        this->profit = profit;
    }
};

bool compare(Task* a,Task* b)
{
	return a-> profit > b -> profit;
}
int getMaxProfit(vector<Task*> &tasks) 
{
    // add your logic here
	sort(tasks.begin(),tasks.end(),compare);
	int res = 0;
	int *r = new int(tasks.size()-1);
	for(int i = 0;i < tasks.size();i++)
	{
		if(r[tasks[i]->deadline] != 1)
		{
			r[tasks[i]->deadline] = 1;
			res = res + tasks[i]->profit;
		}
		else
		{
			int j = tasks[i]->deadline;
			while(j > 0)
			{
				if(r[j] != 1)
				{
					r[j] = 1;
					res = res + tasks[j]->profit;
					break;
				}
				else
				{
					j--;
				}
			}
		}
	}
	return res;
}

int main()
{
	int n;
    vector<Task*>s;
	cout << "Enter The size: " << endl;
	cin >> n;
    for(int i = 0;i < n;i++)
    {
		int dead,prof;
		cout << "enter";
        cin >> dead >> prof;
    	Task* a = new Task(dead,prof);
    
        
        // a->deadline = dead;
		// a->profit = prof;
        s.push_back(a);
    }

    int res = getMaxProfit(s);
    cout << res;
    return 0;
}