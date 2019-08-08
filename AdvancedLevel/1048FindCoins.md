# Find Coins
Eva loves to collect coins from all over the universe, including some other planets like Mars. One day she visited a universal shopping mall which could accept all kinds of coins as payments. However, there was a special requirement of the payment: for each bill, she could only use exactly two coins to pay the exact amount. Since she has as many as 10^5 coins with her, she definitely needs your help. You are supposed to tell her, for any given amount of money, whether or not she can find two coins to pay for it.
### Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive numbers: N (<=10^5??, the total number of coins) and M (<=10^3, the amount of money Eva has to pay). The second line contains N face values of the coins, which are all positive numbers no more than 500. All the numbers in a line are separated by a space.
### Output Specification:
For each test case, print in one line the two face values V1 and V2 (separated by a space) such that V1+V2=M and V1<=V?2. If such a solution is not unique, output the one with the smallest V1. If there is no solution, output No Solution instead.
### Sample Input 1:
```
8 15
1 2 8 7 2 4 11 15
```
### Sample Output 1:
```
4 11
```
### Sample Input 2:
```
7 14
1 8 7 2 4 11 15
```
### Sample Output 2:
```
No Solution
```
### Solution
Binary Search, Oh hu~
```C++
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> coins;
    int N, M, face, min, max, middle;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> face;
        if (face < M)
        {
            coins.push_back(face);
        }
    }
    sort(coins.begin(), coins.end(), less<int>());
    for (int i = 0; i < coins.size(); i++)
    {
        min = i + 1;
        max = coins.size() - 1;
        while (min <= max)
        {
            middle = (min + max) / 2;
            if (coins[middle] < M - coins[i])
            {
                min = middle + 1;
            }
            else if (coins[middle] > M - coins[i])
            {
                max = middle - 1;
            }
            else
            {
                cout << coins[i] << " " << coins[middle];
                return 0;
            }
        }
    }
    cout << "No Solution";
    return 0;
}
```