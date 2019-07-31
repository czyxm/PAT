# Reversible Primes

A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (<105) and D (1<D<=10), you are supposed to tell if N is a reversible prime with radix D.

### Input Specification:
The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

### Output Specification:
For each test case, print in one line Yes if N is a reversible prime with radix D, or No if not.

### Sample Input:
```in
73 10
23 2
23 10
-2
```

### Sample Output:
```out
Yes
Yes
No
```

### Solution
This problem is easy but it's important to make the real meaning of **'reversible'** clear: 
The given number N with radix 10 need to be converted to radix D and reversed in radix D, and then converted to radix 10 to check if is prime.


```C++
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//Determine if the number is prime
bool isPrime(int n)
{
    int m = n / 2;
    if (n == 1)
    {
        return false;
    }
    if (n == 2)
    {
        return true;
    }
    for (int i = 2; i <= m; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
//Convert string into int with radix r
int convertToInt(const string & str, int r)
{
    int res = 0, i;
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] != '0')
        {
            break;
        }
    }
    for (; i < str.size(); i++)
    {
        res = res * r + str[i] - '0';
    }
    return res;
}
//Convert int into string from radix 10 to r
string convertToString(int n, int r)
{
    string str;
    while (n > 0)
    {
        str.insert(str.begin(), '0' + n % r);
        n /= r;
    }
    return str;
}

int main()
{
    int N, D;
    string str;
    while (true)
    {
        cin >> N;
        if (N < 0)
        {
            break;
        }
        cin >> D;
        str = convertToString(N, D);
        reverse(str.begin(), str.end());
        if (isPrime(N) && isPrime(convertToInt(str, D)))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
```