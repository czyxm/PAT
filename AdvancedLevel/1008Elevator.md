# Elevator
The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.

For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.

### Input Specification:
Each input file contains one test case. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100.

### Output Specification:
For each test case, print the total time on a single line.

### Sample Input:
```in
3 2 3 1
```

### Sample Output:
```out
41
```

### Solution
Deal with the up floor/down floor each step, and finally add up the stay time.
```C++
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
```