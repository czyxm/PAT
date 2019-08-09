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