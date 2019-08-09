#include<iostream>
#include<string>
using namespace std;

int main()
{
    int M;
    string unlockId, lockId, minTime = "24:00:00", maxTime = "00:00:00", id, inTime, outTime;
    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> id >> inTime >> outTime;
        if (inTime < minTime)
        {
            minTime = inTime;
            unlockId = id;
        }
        if (outTime > maxTime)
        {
            maxTime = outTime;
            lockId = id;
        }
    }
    cout << unlockId << " " << lockId;
}