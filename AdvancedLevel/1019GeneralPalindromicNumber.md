# General Palindromic Number
A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.
Although palindromic numbers are most often considered in the decimal system, the concept of palindromicity can be applied to the natural numbers in any numeral system. Consider a number N>0 in base b��2, where it is written in standard notation with k+1 digits ai as $\sum_{i=0}^k{a_ib^i}$. Here, as usual, 0��ai < b for all i and akis non-zero. Then N is palindromic if and only if a?i=ak?i for all i. Zero is written 0 in any base and is also palindromic by definition.
Given any positive decimal integer N and a base b, you are supposed to tell if N is a palindromic number in base b.
### Input Specification:
Each input file contains one test case. Each case consists of two positive numbers N and b, where 0<N<=10^?9 is the decimal number and 2<=b<=10^9
?? is the base. The numbers are separated by a space.
### Output Specification:
For each test case, first print in one line Yes if N is a palindromic number in base b, or No if not. Then in the next line, print N as the number in base b in the form "ak ak?1 ... a0??". Notice that there must be no extra space at the end of output.
### Sample Input 1:
```in
27 2
```
### Sample Output 1:
```out
Yes
1 1 0 1 1
```
### Sample Input 2:
```in
121 5
```
### Sample Output 2:
```out
No
4 4 1
```
### Solution
Oh hu~
```C++
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    long long N, R;
    int flag = true;
    vector<long long> digit;
    cin >> N >> R;
    if (N == 0)
    {
        cout << "Yes" << endl << "0";
        return 0;
    }
    while (N > 0)
    {
        digit.push_back(N % R);
        N /= R;
    }
    for (int i = 0, j = digit.size() - 1; i < j; i++, j--)
    {
        if (digit[i] != digit[j])
        {
            cout << "No" << endl;
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "Yes" << endl;
    }
    for (int i = digit.size() - 1; i >= 0; i--)
    {
        cout << digit[i];
        if (i > 0)
        {
            cout << " ";
        }
    }
    return 0;
}
```