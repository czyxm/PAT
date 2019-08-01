# Queueing at Bank

Suppose a bank has K windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. All the customers have to wait in line behind the yellow line, until it is his/her turn to be served and there is a window available. It is assumed that no window can be occupied by a single customer for more than 1 hour.

Now given the arriving time T and the processing time P of each customer, you are supposed to tell the average waiting time of all the customers.

### Input Specification:
Each input file contains one test case. For each case, the first line contains 2 numbers: N (¡Ü10
?4
?? ) - the total number of customers, and K (¡Ü100) - the number of windows. Then N lines follow, each contains 2 times: HH:MM:SS - the arriving time, and P - the processing time in minutes of a customer. Here HH is in the range [00, 23], MM and SS are both in [00, 59]. It is assumed that no two customers arrives at the same time.

Notice that the bank opens from 08:00 to 17:00. Anyone arrives early will have to wait in line till 08:00, and anyone comes too late (at or after 17:00:01) will not be served nor counted into the average.

### Output Specification:
For each test case, print in one line the average waiting time of all the customers, in minutes and accurate up to 1 decimal place.

### Sample Input:
```in
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
```

### Sample Output:
```out
8.2
```

### Solution
```C++
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
```