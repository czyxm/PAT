#include<bits/stdc++.h>
using namespace std;

int _hash(char ch)
{
    if ('0' <= ch && ch <= '9')
    {
        return ch - '0';
    }
    else if ('A' <= ch && ch <= 'Z')
    {
        return ch - 'A' + 10;
    }
    else
    {
        return ch - 'a' + 36;
    }
}

int main()
{
    int shopBeads[62] = {0}, evaBeads[62] = {0}, missingNum = 0, extraNum = 0;
    string shopStr, evaStr;
    cin >> shopStr >> evaStr;
    for (int i = 0; i < shopStr.size(); i++)
    {
        shopBeads[_hash(shopStr[i])]++;
    }
    for (int i = 0; i < evaStr.size(); i++)
    {
        evaBeads[_hash(evaStr[i])]++;
    }
    for (int i = 0; i < 62; i++)
    {
        if (shopBeads[i] < evaBeads[i])
        {
            missingNum += evaBeads[i] - shopBeads[i];
        }
        else
        {
            extraNum += shopBeads[i] - evaBeads[i];
        }
    }
    if (missingNum > 0)
    {
        cout << "No " << missingNum;
    }
    else
    {
        cout << "Yes " << extraNum;
    }
}