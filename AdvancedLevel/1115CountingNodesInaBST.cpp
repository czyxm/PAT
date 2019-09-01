#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, M, num, minNum, diff = 0, sum1 = 0, sum2 = 0;
    priority_queue<int, vector<int>, greater<vector<int>::value_type> > minHeap;
    cin >> N;
    M = N >> 1;
    if ((N & 1) == 1)
    {
        M++;
        diff = 1;
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        if (minHeap.size() < M)
        {
            sum1 += num;
            minHeap.push(num);
        }
        else
        {
            minNum = minHeap.top();
            if (num > minNum)
            {
                sum1 += num - minNum;
                sum2 += minNum;
                minHeap.pop();
                minHeap.push(num);
            }
            else
            {
                sum2 += num;
            }
        }
    }
    cout << diff << " " << sum1 - sum2;
    return 0;
}