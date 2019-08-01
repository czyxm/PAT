# Phone Bills

A long-distance telephone company charges its customers by the following rules:

Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.

### Input Specification:
Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.

The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.

The next line contains a positive number N (¡Ü1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word on-line or off-line.

For each test case, all dates will be within a single month. Each on-line record is paired with the chronologically next record for the same customer provided it is an off-line record. Any on-line records that are not paired with an off-line record are ignored, as are off-line records not paired with an on-line record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.

### Output Specification:
For each test case, you must print a phone bill for each customer.

Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.

### Sample Input:
```in
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
```
### Sample Output:
```out
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
```
### Solution
This problem is logically simple: Set up a map from customers' names to its structure node containing some necessary information including--
* Phone records
* Valid calls
* Total amount

The reason I use 'map' is that it's easy to determine whether the next customer has appeared by function 'find()'.
First group all the records with the same name and then sort them by generic algorithm chronologically so as to abstract valid calls. 
Secondly, we need to make sure that the cost is right. While displaying the result, note that the customer who has no valid calls will not be displayed...This trap made me nearly mad :)

```C++
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
```