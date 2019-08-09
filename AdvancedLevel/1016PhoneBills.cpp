#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
//Structure node of record
typedef struct RecordNode
{
    string time;
    string type;
}* RNode;
//Structure node of call
typedef struct CallNode
{
    string startTime;
    string endTime;
    int lastTime;
    float cost;
}* CNode;
//Structure node of customer
struct CustomerNode
{
    vector<CNode> calls;
    vector<RNode> records;
    float totalAmount;
};
//Comparing function for sort records
bool compare(const RNode & r1, const RNode & r2)
{
    return r1->time < r2->time;
}
//The difference of start time and end time in minutes
int difference(const string & startTime, const string & endTime)
{
    int startMinute, endMinute;
    startMinute = 1440 * stoi(startTime.substr(0, 2)) + 60 * stoi(startTime.substr(3, 2)) + stoi(startTime.substr(6, 2));
    endMinute = 1440 * stoi(endTime.substr(0, 2)) + 60 * stoi(endTime.substr(3, 2)) + stoi(endTime.substr(6, 2));
    return endMinute - startMinute;
}
//Caculate the cost
int cost(const string & startTime, const string & endTime, int * rate)
{
    int cents = 0;
    int startDay = stoi(startTime.substr(0, 2)), startHour = stoi(startTime.substr(3, 2)), startMinute = stoi(startTime.substr(6, 2));
    int endDay = stoi(endTime.substr(0, 2)), endHour = stoi(endTime.substr(3, 2)), endMinute = stoi(endTime.substr(6, 2));
    //The call starts and ends in an hour
    if (startDay == endDay && startHour == endHour)
    {
        cents += rate[startHour] * (endMinute - startMinute);
    }
    else
    {
        //Deal with the minute part
        cents += rate[startHour++] * (60 - startMinute) + rate[endHour--] * endMinute;
        //Deal with the day part
        endHour += (endDay - startDay) * 24;
        //Deal with the hour part
        for (int i = startHour; i <= endHour; i++)
        {
            cents += rate[i % 24] * 60;
        }
    }
    return cents;
}

int main()
{
    int N, rate[24];
    string name, month;
    map<string, CustomerNode *, less<string>> customer;
    //Read input data
    for (int i = 0; i < 24; i++)
    {
        cin >> rate[i];
    }
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        RNode newRecord = new RecordNode;
        cin >> name >> newRecord->time >> newRecord->type;
        auto iter = customer.find(name);
        if (iter == customer.end())
        {
            CustomerNode * newCustomer = new CustomerNode;
            newCustomer->totalAmount = 0;
            newCustomer->records.push_back(newRecord);
            customer.insert(pair<string, CustomerNode *>(name, newCustomer));
        }
        else
        {
            iter->second->records.push_back(newRecord);
        }
    }
    month = customer.begin()->second->records[0]->time.substr(0, 2);
    //Sort the records of each customer chronologically
    //Abrtract the valid calls 
    //Display the result
    auto cbegin = customer.begin(), cend = customer.end();
    while (cbegin != cend)
    {
        vector<RNode> & records = cbegin->second->records;
        sort(records.begin(), records.end(), compare);
        for (int i = 0; i < records.size() - 1; i++)
        {
            //Find valid calls
            if (records[i]->type == "on-line" && records[i + 1]->type == "off-line")
            {
                CNode newCall = new CallNode;
                newCall->startTime = records[i]->time.substr(3);
                newCall->endTime = records[i + 1]->time.substr(3);
                newCall->lastTime = difference(newCall->startTime, newCall->endTime);
                cbegin->second->totalAmount += newCall->cost = cost(newCall->startTime, newCall->endTime, rate) / 100.0;
                cbegin->second->calls.push_back(newCall);
                i++;
            }
        }
        vector<CNode> & calls = cbegin->second->calls;
        if (calls.size() > 0)  //Just display the information of customers that have valid calls
        {
            cout << cbegin->first << " " << month << endl;
            for (int i = 0; i < calls.size(); i++)
            {
                cout << calls[i]->startTime << " " << calls[i]->endTime << " " << calls[i]->lastTime << " $" << setprecision(2) << fixed << calls[i]->cost << endl;
            }
            cout << "Total amount: $" << setprecision(2) << fixed << cbegin->second->totalAmount << endl;
        }
        cbegin++;
    }
    return 0;
}