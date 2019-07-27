# Maximum Subsequence Sum

Given a sequence of *K* integers { *N*1, *N*2, ..., *N**K* }. A continuous subsequence is defined to be { *N**i*, *N**i*+1, ..., *N**j* } where 1≤*i*≤*j*≤*K*. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

### Input Specification:

Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer *K* (≤10000). The second line contains *K* numbers, separated by a space.

### Output Specification:

For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices *i* and *j*(as shown by the sample case). If all the *K* numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

### Sample Input:

```in
10
-10 1 2 3 4 -5 -23 3 7 -21
```

### Sample Output:

```out
10 1 4
```

---

### Solution

This is a typical DP problem. Let S~i~ denote the max sum of continuous sequence end with a~i~, we can get that:
S~i~ = max { S~i-1~ + a~i~, a~i~}

```C++
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
```

