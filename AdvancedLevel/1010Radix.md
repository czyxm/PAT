# Radix
Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is yes, if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.

### Input Specification:
Each input file contains one test case. Each case occupies a line which contains 4 positive integers:
```
N1 N2 tag radix
```
Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set { 0-9, a-z } where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number radix is the radix of N1 if tag is 1, or of N2 if tag is 2.

### Output Specification:
For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print Impossible. If the solution is not unique, output the smallest possible radix.

### Sample Input 1:
```in
6 110 1 10
```

### Sample Output 1:
```out
2
```

### Sample Input 2:
```in
1 ab 1 2
```

### Sample Output 2:
```out
Impossible
```

### Solution
To make value1 equals value2, the first step is to caculate value1 in the known radix and then search a proper radix for value2 from the minimum to the maximum. This problem seems not to be complex, but indeed, it needs utmost carefulness because of several error-prone details:
* You must consider the overflow while converting the string to number.[`long long` data type maybe also not enough]
* The minmum and maximum value of unknown radix are the maximum digit **plus 1** in strN2 and the value **plus 1** of strN1 respectively
* Binary search is used to reduce the search time avoiding time out error


```C++
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
```