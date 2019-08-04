# Median
Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1 = { 11, 12, 13, 14 } is 12, and the median of S2 = { 9, 10, 15, 16, 17 } is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.
Given two increasing sequences of integers, you are asked to find their median.
### Input Specification:
Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (<=2¡Á10^5) is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.
### Output Specification:
For each test case you should output the median of the two given sequences in a line.
### Sample Input:
```in
4 11 12 13 14
5 9 10 15 16 17
```
### Sample Output:
```out
13
```
### Solution
It seems not difficult to AC but the only problem is MLE! (After all the memory limit is 1.5M) Anyway the first sequence and the length of sequence 1 and sequence 2 need to be stored, and a method to save memory is that figure out the position of median and just keep numbers before this position. Thus we need to pop out those redundant numbers till the size of sequence eaquals `position` after each input of sequence 2. Considering we only need to know the largest one amoung the numbers before `position` and a sort operation is needed after each input, priority queue is very proper to keep the numbers.

Moreover, sometimes there's still one point causing MLE while sometimes this works. Maybe it depends on the specific cost of each run.
```C++
#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<int> sequence;
    int N1, N2, number;
    cin >> N1;
    for (int i = 1; i <= N1; i++)
    {
        cin >> number;
        sequence.push(number);
    }
    cin >> N2;
    //Caculate the position of median
    N1 += N2;
    if (N1 & 1)
    {
        N1++;
    }
    N1 >>= 1;
    while (sequence.size() > N1)
    {
        sequence.pop();
    }
    for (int i = 1; i <= N2; i++)
    {
        cin >> number;
        sequence.push(number);
        if (sequence.size() > N1)
        {
            sequence.pop();
        }
    }
    cout << sequence.top();
    return 0;
}
```