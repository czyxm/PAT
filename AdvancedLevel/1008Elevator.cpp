#include<iostream>
using namespace std;

int main()
{
    int N, lastLevel = 0, curLevel = 0, totalTime = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> curLevel;
        if (curLevel > lastLevel)
        {
            totalTime += (curLevel - lastLevel) * 6;
        }
        else
        {
            totalTime += (lastLevel - curLevel) * 4;
        }
        lastLevel = curLevel;
    }
    totalTime += N * 5;
    cout << totalTime;

    return 0;
}