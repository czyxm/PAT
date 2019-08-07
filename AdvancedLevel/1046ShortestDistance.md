# Shortest Distance
The task is really simple: given N exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.
### Input Specification:
Each input file contains one test case. For each case, the first line contains an integer N (in [3,10^5]), followed by N integer distances D1 D2 ... D?N, where Di is the distance between the i-th and the (i+1)-st exits, and D?N is between the N-th and the 1st exits. All the numbers in a line are separated by a space. The second line gives a positive integer M (<=10^4), with M lines follow, each contains a pair of exit numbers, provided that the exits are numbered from 1 to N. It is guaranteed that the total round trip distance is no more than 10^7.
### Output Specification:
For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.
### Sample Input:
```
5 1 2 4 14 9
3
1 3
2 5
4 1
```
### Sample Output:
```
3
10
7
```
### Solution
Oh hu~
```C++
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> distance;
    int N, M, source, target, total = 0, shortestDistance;
    cin >> N;
    distance.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> distance[i];
        total += distance[i];
    }
    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> source >> target;
        if (source > target)
        {
            swap(source, target);
        }
        shortestDistance = 0;
        for (int j = source - 1; j <= target - 2; j++)
        {
            shortestDistance += distance[j];
        }
        shortestDistance = shortestDistance < (total - shortestDistance) ? shortestDistance : total - shortestDistance;
        cout << shortestDistance << endl;
    }
    return 0;
}
```