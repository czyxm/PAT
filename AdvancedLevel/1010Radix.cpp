#include<iostream>
#include<string>
using namespace std;
//Convert the digit from char to int
//0-9 : 0-9
//a-z : 10-35
int valueOf(char symbol)
{
    if ('0' <= symbol && symbol <= '9')
    {
        return symbol - '0';
    }
    else if ('a' <= symbol && symbol <= 'z')
    {
        return symbol - 'a' + 10;
    }
    else
    {
        return 0;
    }
}
//Caculate the value of str in radix
long long valueOf(const string & str, long long radix)
{
    long long value = 0;
    for (int i = 0; i < str.size(); i++)
    {
        value = value * radix + valueOf(str[i]);
        //Overflow
        if (value < 0)
        {
            return -1;
        }
    }
    return value;
}

int main()
{
    string strN1, strN2;
    int tag;
    long long radix, value1, value2, max, min, mid, res;
    cin >> strN1 >> strN2 >> tag >> radix;
    //Swap strN1 and strN2 if tag = 2
    //Make sure that the radix of the first string is known
    if (tag == 2)
    {
        swap(strN1, strN2);
    }
    //Caculate the value of strN1 in radix for later use
    value1 = valueOf(strN1, radix);
    //The ceiling of binary search is the value of strN1 plus 1
    max = value1 + 1;
    //The floor of binary search is the max digit of strN2 plus 1
    min = 1;
    for (int i = 0; i < strN2.size(); i++)
    {
        if (valueOf(strN2[i]) > min)
        {
            min = valueOf(strN2[i]);
        }
    }
    min++;
    //Initialize the result
    res = -1;
    //Binary search
    while (min <= max)
    {
        mid = (min + max) / 2;
        value2 = valueOf(strN2, mid);
        if (value2 <= 0 || value2 > value1)
        {
            max = mid - 1;
        }
        else if (value2 < value1)
        {
            min = mid + 1;
        }
        else
        {
            //Record one of the results and continue to find a smaller one
            res = mid;
            max = mid - 1;
        }
    }
    //Display the result
    if (res == -1)
        cout << "Impossible";
    else
        cout << res;
    return 0;
}