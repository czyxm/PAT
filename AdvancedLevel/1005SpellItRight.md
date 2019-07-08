# Spell It Right

Given a non-negative integer *N*, your task is to compute the sum of all the digits of *N*, and output every digit of the sum in English.

### Input Specification:

Each input file contains one test case. Each case occupies one line which contains an *N* (≤10100).

### Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

### Sample Input:

```in
12345
```

### Sample Output:

```out
one five
```

---

### Solution
```C++
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string number, numStr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int sum = 0;
    cin >> number;
    for (int i = 0; i < number.length(); i++)
    {
        sum += number[i] - '0';
    }
    number = to_string(sum);
    for (int i = 0; i < number.length(); i++)
    {
        cout << numStr[number[i] - '0'];
        if (i < number.length() - 1)
        {
            cout << " ";
        }
    }
    return 0;
}
```

