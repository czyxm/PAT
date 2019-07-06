# A+B Format

Calculate *a*+*b* and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

### Input Specification:

Each input file contains one test case. Each case contains a pair of integers *a* and *b* where ??¡¯106?¡ë¡è*a*,*b*?¡ë¡è106. The numbers are separated by a space.

### Output Specification:

For each test case, you should output the sum of *a* and *b* in one line. The sum must be written in the standard format.

### Sample Input:

```in
-1000000 9
```

### Sample Output:

```out
-999,991
```

---

### Solution

```C++
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int operand1, operand2, res;
    cin >> operand1 >> operand2;
    res = operand1 + operand2;
    string resStr = to_string(abs(res));
    for (int i = resStr.length() - 4; i >= 0; i -= 3)
    {
        resStr.insert(i + 1, 1, ',');
    }
    if (res < 0)
    {
        resStr = '-' + resStr;
    }
    cout << resStr;
}
```



