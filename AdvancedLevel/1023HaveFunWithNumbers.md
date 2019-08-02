# Have Fun with Numbers
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!
Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.
### Input Specification:
Each input contains one test case. Each case contains one positive integer with no more than 20 digits.
### Output Specification:
For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.
### Sample Input:
```in
1234567899
```
### Sample Output:
```out
Yes
2469135798
```
### Solution
Oh hu~
```C++
#include<iostream>
#include<string>
using namespace std;

bool equal(string s1, string s2)
{
    int i, j;
    if (s1.size() != s2.size())
    {
        return false;
    }
    for (i = 0; i < s1.size(); i++)
    {
        for (j = 0; j < s2.size(); j++)
        {
            if (s1[i] == s2[j])
            {
                s2[j] = '-';
                break;
            }
        }
        if (j >= s2.size())
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s1, s2;
    int digit, carry = 0;
    cin >> s1;
    for (int i = s1.size() - 1; i >= 0; i--)
    {
        digit = (s1[i] - '0') * 2 + carry;
        if (digit >= 10)
        {
            digit -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        s2 = to_string(digit) + s2;
    }
    if (carry == 1)
    {
        s2 = "1" + s2;
    }
    if (carry != 0 || !equal(s1, s2))
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    cout << s2 << endl;
    return 0;
}
```