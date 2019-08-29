#include<bits/stdc++.h>
using namespace std;

int main()
{
    const long MAX = 1000000007;
    long pNum = 0, paNum = 0, patNum = 0;
    char ch;
    while ((ch = getchar()) != '\n')
    {
        if (ch == 'P')
        {
            pNum++;
        }
        else if (ch == 'A')
        {
            paNum += pNum;
            if (paNum >= MAX)
            {
                paNum -= MAX;
            }
        }
        else if (ch == 'T')
        {
            patNum += paNum;
            if (patNum >= MAX)
            {
                patNum -= MAX;
            }
        }
    }
    cout << patNum;
    return 0;
}