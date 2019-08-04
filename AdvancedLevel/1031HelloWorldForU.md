# Hello World for U
Given any string of N (¡£=5) characters, you are asked to form the characters into the shape of U. For example, helloworld can be printed as:
```
h  d
e  l
l  r
lowo
```
That is, the characters must be printed in the original order, starting top-down from the left vertical line with n1 characters, then left to right along the bottom line with n2 characters, and finally bottom-up along the vertical line with n3 characters. And more, we would like U to be as squared as possible -- that is, it must be satisfied that n1=n?3=max { k | k<=n2 for all 3<=n2<=N } with n1+n2+n3???2=N.
### Input Specification:
Each input file contains one test case. Each case contains one string with no less than 5 and no more than 80 characters in a line. The string contains no white space.
### Output Specification:
For each test case, print the input string in the shape of U as specified in the description.
### Sample Input:
```in
helloworld!
```
### Sample Output:
```out
h   !
e   d
l   l
lowor
```
### Solution
Oh hu~
```C++
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int N1, N2;
    string text;
    cin >> text;
    for (N2 = 3; N2 <= text.size(); N2++)
    {
        N1 = text.size() + 2 - N2;
        //Make sure N1 is even
        if ((N1 & 1) == 0)
        {
            N1 >>= 1;
            if (N1 <= N2)
            {
                break;
            }
        }
    }
    //Display the U-shape result
    for (int i = 0; i < N1 - 1; i++)
    {
        cout << text[i];
        for (int j = 1; j <= N2 - 2; j++)
        {
            cout << " ";
        }
        cout << text[text.size() - 1 - i] << endl;
    }
    for (int i = 0; i < N2; i++)
    {
        cout << text[N1 - 1 + i];
    }
    return 0;
}
```