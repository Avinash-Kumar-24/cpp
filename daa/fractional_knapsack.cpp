/* Write a code to solve fractional knapsack Problem in o(nlgn) time */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Grain 
{
    public:
        int weight, value;
        Grain(int weight, int value) 
        {
            this->weight = weight;
            this->value = value;
        }
};

bool compare(Grain* a,Grain* b)
{
	double ratio_of_a = (double)a->value/a->weight;
	// cout << ratio_of_a << endl;
	double ratio_of_b = (double)b->value/b->weight;
	// cout << ratio_of_b << endl;
	return ratio_of_a > ratio_of_b;
}
double maxSackValue(vector<Grain*> &grains, int w) 
{
	sort(grains.begin(),grains.end(),compare);

	double res=0.0;
	
	int i = 0;
	while(w - grains[i]->weight > 0 && i < grains.size())
	{ 
		res = res + grains[i] -> value;
		w = w- grains[i]-> weight;
	 	i++;
	}
	if(w > 0 && i < grains.size())
	{
		double we = (double)w;
		double temp = (grains[i]->value*we)/grains[i]->weight;
		res = res + temp;
	}
	return res;
}

int main()
{
    vector<Grain*>grain;
    int n,weight,value;
    int wt;
    int res;
    cout << "Enter the number of types :"<< endl;
    cin >> n;
    cout << "Enter the key weight : ";
    cin >> wt;
    for(int i = 0;i < n;i++)
    {
        cout << "Enter the weight ";
        cin >> weight;
        cout << "Enter the value ";
        cin >> value;
        Grain *pt = new Grain(weight,value);
        grain.push_back(pt);
    }
    res = maxSackValue(grain,wt);
    cout << "The maximum Profit is : ";
    cout << res;
    return 0;
}

/*
######  Input 1 #####

Enter the number of types : 4
Enter the key weight : 60
Enter the weight 40
Enter the value 280
Enter the weight 10
Enter the value 100
Enter the weight 20
Enter the value 120
Enter the weight 24
Enter the value 120
###### OutPut 1 #####
The Maximum Profit is: 440
*/