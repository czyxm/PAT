# Palindromic Number
A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.
Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.
Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.
### Input Specification:
Each input file contains one test case. Each case consists of two positive numbers N and K, where N (<=10^10) is the initial numer and K (<=100)is the maximum number of steps. The numbers are separated by a space.
### Output Specification:
For each test case, output two numbers, one in each line. The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number. If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.
### Sample Input 1:
```in
67 3
```
### Sample Output 1:
```out
484
2
```
### Sample Input 2:
```in
69 3
```
### Sample Output 2:
```out
1353
3
```
### Solution
Oh hu~
```C++
#include<iostream>
#include<string>
using namespace std;

bool isPalindromic(const string & s)
{
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            return false;
        }
    }
    return true;
}

void doubleStr(string & s)
{
    int digit, carry = 0;
    string _s = s;
    for (int i = s.size() - 1, j = 0; i >= 0; i--, j++)
    {
        digit = (s[i] - '0' + _s[j] - '0') + carry;
        if (digit >= 10)
        {
            digit -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        s[i] = digit + '0';
    }
    if (carry == 1)
    {
        s = "1" + s;
    }
}

int main()
{
    string s;
    int K;
    cin >> s >> K;
    for (int i = 0; i < K; i++)
    {
        if (isPalindromic(s))
        {
            cout << s << endl << i << endl;
            return 0;
        }
        else
        {
            doubleStr(s);
        }
    }
    cout << s << endl << K << endl;
    return 0;
}
```