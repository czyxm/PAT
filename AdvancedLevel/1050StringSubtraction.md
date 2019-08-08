# String Subtraction
Given two strings S1 and S2, S=S1-S2 is defined to be the remaining string after taking all the characters in S2 from S1. Your task is simply to calculate S1-S2 for any given strings. However, it might not be that simple to do it fast.
### Input Specification:
Each input file contains one test case. Each case consists of two lines which gives S1 and S2, respectively. The string lengths of both strings are no more than 10^4??. It is guaranteed that all the characters are visible ASCII codes and white space, and a new line character signals the end of a string.
### Output Specification:
For each test case, print S?1-S?2 in one line.
### Sample Input:
```
They are students.
aeiou
```
### Sample Output:
```
Thy r stdnts.
```
### Solution
Oh hu~
```C++
#include<iostream>
#include<set>
using namespace std;

int main()
{
    char S1[10001] = {'\0'}, ch;
    set<char> S2;
    cin.getline(S1, 10001, '\n');
    while((ch = getchar()) != '\n')
    {
        S2.insert(ch);
    }
    for (int i = 0; S1[i]; i++)
    {
        if (S2.find(S1[i]) == S2.end())
        {
            cout << S1[i];
        }
    }
    return 0;
}
```