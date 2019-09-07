#include<bits/stdc++.h>
using namespace std;

bool isPalindromic(const string & str)
{
    int i = 0, j = str.size() - 1;
    while (i < j && str[i] == str[j])
    {
        i++;
        j--;
    }
    return i < j ? false : true;
}

string add(const string & str1, const string & str2)
{
    string str;
    int carry = 0, digit;
    for (int i = str1.size() - 1; i >= 0; i--)
    {
        digit = str1[i] + str2[i] + carry - '0' - '0';
        if (digit >= 10)
        {
            carry = 1;
            digit -= 10;
        }
        else
        {
            carry = 0;
        }
        str = to_string(digit) + str;
    }
    if (carry == 1)
    {
        str = "1" + str;
    }
    return str;
}

int main()
{
    int iteration = 10;
    string strA, strB, strC;
    cin >> strA;
    while (iteration > 0 && !isPalindromic(strA))
    {
        strB = strA;
        reverse(strB.begin(), strB.end());
        strC = add(strA, strB);
        cout << strA << " + " << strB << " = " << strC << endl;
        strA = strC;
        iteration--;
    }
    if (iteration > 0)
    {
        cout << strA << " is a palindromic number." << endl;
    }
    else
    {
        cout << "Not found in 10 iterations." << endl;
    }
    return 0;
}