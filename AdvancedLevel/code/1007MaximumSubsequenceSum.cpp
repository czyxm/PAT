#include<iostream>
using namespace std;
/*Let sum[i] denote the max sum of the continous suquence
 *endding with data[i], then the DP recursive fomula:
 *>>  sum[i] = max{ sum[i] + data[i], data[i]}  <<
 */
int main()
{
    int N, *data, *sum, *start, maxSumIdx;
    cin >> N;
    data = new int[N];  //Input data
    sum = new int[N];   //sum[i]
    start = new int[N]; //start element
    for (int i = 0; i < N; i++)
    {
        cin >> data[i];
    }
    maxSumIdx = 0;      //The index of max sum
    start[0] = sum[0] = data[0];

    for (int i = 1; i < N; i++)
    {
        //Caculate sum[i]
        if (data[i] + sum [i - 1] >= data[i])
        {
            sum[i] = data[i] + sum [i - 1];
            start[i] = start[i - 1];
        }
        else
        {
            start[i] = sum[i] = data[i];
        }
        //Refresh the index of max sum
        if (sum[i] > sum[maxSumIdx])
        {
            maxSumIdx = i;
        }
    }
    if (sum[maxSumIdx] < 0)
    {
        //All the element is negative
        cout << 0 << " " << data[0] << " " << data[N - 1];
    }
    else
    {
        cout << sum[maxSumIdx] << " " << start[maxSumIdx] << " " << data[maxSumIdx];
    }
    delete [] data;
    delete [] start;
    delete [] sum;
}