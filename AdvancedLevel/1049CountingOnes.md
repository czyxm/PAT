# Counting Ones
The task is simple: given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N. For example, given N being 12, there are five 1's in 1, 10, 11, and 12.
### Input Specification:
Each input file contains one test case which gives the positive N (<=2^30).
### Output Specification:
For each test case, print the number of 1's in one line.
### Sample Input:
12
### Sample Output:
5
### Solution
Count 1's at each bit respectively.
```C++
#include<iostream>
using namespace std;

int main()
{
    long N, R = 10, count = 0;
    cin >> N;
    while (R <= 10 * N)
    {
        count += N / R * R / 10;
        if (N % R * 10 / R > 1)
        {
            count += R / 10;
        }
        else if (N % R * 10 / R == 1)
        {
            if (R == 10)
            {
                count += 1;
            }
            else
            {
                count += N % (R / 10) + 1;
            }
        }
        R *= 10;
    }
    cout << count;
}
```