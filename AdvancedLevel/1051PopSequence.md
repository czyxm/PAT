# Pop Sequence
Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.
### Input Specification:
Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.
### Output Specification:
For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.
### Sample Input:
```
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
```
### Sample Output:
```
YES
NO
NO
YES
NO
```
### Solution
Oh hu~
```C++
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> stack, sequence;
    int M, N, K, num;
    bool possible;
    cin >> M >> N >> K;
    sequence.resize(N);
    for (int i = 1; i <= K; i++)
    {
        num = 0; //The current test number
        possible = true;
        stack.clear();
        for (int j = 0; j < N; j++)
        {
            cin >> sequence[j];
            if (num < sequence[j])
            {
                if (sequence[j] - num <= M - stack.size())
                {
                    for (int k = num + 1; k < sequence[j]; k++)
                    {
                        stack.push_back(k);
                    }
                    num = sequence[j];
                }
                else
                {
                    possible = false;
                }
            }
            else if (num > sequence[j])
            {
                if (sequence[j] != stack.back())
                {
                    possible = false;
                }
                stack.pop_back();
            }
            else
            {
                possible = false;
            }
        }
        if (possible)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
```