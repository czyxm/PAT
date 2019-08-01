#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//Structure node for customer
typedef struct CustomerNode
{
    int arriveTime;
    int processingTime;
}* CNode;
//Compare function for sorting chronologically
bool compare(const CNode & c1, const CNode & c2)
{
    return c1->arriveTime < c2->arriveTime;
}

int main()
{
    int N, K, index;
    float waitTime = 0;
    string timeStr;
    vector<CNode> customer;
    cin >> N >> K;
    vector<int> windowTime(K, 28800);
    for (int i = 0; i < N; i++)
    {
        CNode newCustomer = new CustomerNode;
        cin >> timeStr >> newCustomer->processingTime;
        //Processing time must be at most one hour
        if (newCustomer->processingTime > 60)
        {
            newCustomer->processingTime = 60;
        }
        newCustomer->processingTime *= 60;  //Transfer to seconds
        //Filter out those later than 17:00:00
        if (timeStr <= "17:00:00")
        {
            newCustomer->arriveTime = stoi(timeStr.substr(0, 2)) * 3600 + stoi(timeStr.substr(3, 2)) * 60 + stoi(timeStr.substr(6, 2));
            customer.push_back(newCustomer);
        }
    }
    sort(customer.begin(), customer.end(), compare);
    for (int i = 0; i < customer.size(); i++)
    {
        //Find the index of the window that finish its current service earliset 
        index = 0; 
        for (int j = 1; j < K; j++)
        {
            if (windowTime[j] < windowTime[index])
            {
                index = j;
            }
        }
        //If the next customer comes later than the window's spare time
        if (customer[i]->arriveTime >= windowTime[index])
        {
            windowTime[index] = customer[i]->arriveTime + customer[i]->processingTime;
        }
        //If the next customer comes earlier than the window's spare time
        else
        {
            waitTime += windowTime[index] - customer[i]->arriveTime;
            windowTime[index] += customer[i]->processingTime;
        }
    }
    if (customer.size() <= 0)
        cout << 0.0 << endl;
    else
        cout << setprecision(1) << fixed << waitTime / (customer.size() * 60);
    return 0;
}