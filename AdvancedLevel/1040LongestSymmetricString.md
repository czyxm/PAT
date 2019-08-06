# Longest Symmetric String
Given a string, you are supposed to output the length of the longest symmetric sub-string. For example, given `Is PAT&TAP symmetric?`, the longest symmetric sub-string is `s PAT&TAP s`, hence you must output `11`.
### Input Specification:
Each input file contains one test case which gives a non-empty string of length no more than 1000.
### Output Specification:
For each test case, simply print the maximum length in a line.
### Sample Input:
```
Is PAT&TAP symmetric?
```
### Sample Output:
```
11
```
### Solution
Seach the string brutely. Oh hu~
```C++
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    bool isSymmetric;
    int maxLength = 1;
    getline(cin, str);
    for (int i = 0; i < str.size() - 1; i++)
    {
        for (int j = i + 1; j < str.size(); j++)
        {
            if (j - i + 1 > maxLength)
            {
                isSymmetric = true;
                for (int p = i, q = j; p < q; p++, q--)
                {
                    if (str[p] != str[q])
                    {
                        isSymmetric = false;
                        break;
                    }
                }
                if (isSymmetric)
                {
                    maxLength = j - i + 1;
                }
            }
        }
    }
    cout << maxLength;
    return 0;
}
```