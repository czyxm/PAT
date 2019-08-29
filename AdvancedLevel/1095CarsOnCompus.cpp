#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

struct Record
{
    char plateNumber[7];
    int time, status;
};

bool compare1(const Record & r1, const Record & r2)
{
    if (strcmp(r1.plateNumber, r2.plateNumber) == 0)
    {
        return r1.time < r2.time;
    }
    return strcmp(r1.plateNumber, r2.plateNumber) < 0;
}

bool compare2(const Record* r1, const Record* r2)
{
    return r1->time < r2->time;
}

int main()
{
    vector<Record> records;
    vector<Record*> validRecords;
    vector<string> plateNumber;
    int N, K, i, time, parkTime = 0, parkNum = 0;
    char * lastPlateNumber = new char[7];
    string timeStr, statusStr;
    cin >> N >> K;
    records.resize(N);
    for (i = 0; i < N; i++)
    {
        cin >> records[i].plateNumber >> timeStr >> statusStr;
        records[i].status = statusStr[0] == 'i' ? 0 : 1;
        records[i].time = stoi(timeStr.substr(0, 2)) * 3600 + stoi(timeStr.substr(3, 2)) * 60 + stoi(timeStr.substr(6, 2));
    }
    sort(records.begin(), records.end(), compare1);
    i = 0;
    while (i < N - 1)
    {
        if (strcmp(records[i].plateNumber, records[i + 1].plateNumber) == 0)
        {
            if (records[i].status == 0 && records[i + 1].status == 1)
            {
                validRecords.push_back(&records[i]);
                validRecords.push_back(&records[i + 1]);
                if (strcmp(lastPlateNumber , records[i].plateNumber) != 0)
                {
                    time = records[i + 1].time - records[i].time;
                    strcpy(lastPlateNumber, records[i].plateNumber);
                }
                else
                {
                    time += records[i + 1].time - records[i].time;
                }
                if (time > parkTime)
                {
                    parkTime = time;
                    plateNumber.clear();
                    plateNumber.push_back(string(records[i].plateNumber));
                }
                else if (time == parkTime)
                {
                    plateNumber.push_back(string(records[i].plateNumber));
                }
                i += 2;
                continue;
            }
        }
        i++;
    }
    sort(validRecords.begin(), validRecords.end(), compare2);
    int index = 0;
    for (int i = 1; i <= K; i++)
    {
        cin >> timeStr;
        time = stoi(timeStr.substr(0, 2)) * 3600 + stoi(timeStr.substr(3, 2)) * 60 + stoi(timeStr.substr(6, 2));
        while (index < validRecords.size() && validRecords[index]->time <= time)
        {
            if (validRecords[index]->status == 0)
            {
                parkNum++;
            }
            else
            {
                parkNum--;
            }
            index++;
        }
        cout << parkNum << endl;
    }
    for (int i = 0; i < plateNumber.size(); i++)
    {
        cout << plateNumber[i] << " ";
    }
    cout << setw(2) << setfill('0') << parkTime / 3600 << ":" << setw(2) << setfill('0') << parkTime / 60 % 60 << ":" << setw(2) << setfill('0') << parkTime % 60;
    return 0;
}