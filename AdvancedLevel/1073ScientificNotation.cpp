#include<bits/stdc++.h>
using namespace std;

int main()
{
    string sNotation;
    char sign;
    cin >> sNotation;
    sign = sNotation[0];
    sNotation.erase(0, 1);
    int pos = sNotation.find('E');
    int zeroNum = stoi(sNotation.substr(pos + 1));
    sNotation.erase(pos);
    if (zeroNum < 0)
    {
        sNotation.erase(1, 1);
        sNotation.insert(0, -zeroNum, '0');
        sNotation.insert(1, 1, '.');
    }
    else
    {
        int spotPos = sNotation.find(".");
        if (zeroNum >= sNotation.size() - spotPos - 1)
        {
            zeroNum -= sNotation.size() - spotPos - 1;
            sNotation += string(zeroNum, '0');
        }
        else
        {
            sNotation.insert(spotPos + zeroNum + 1, 1, '.');
        }
        sNotation.erase(spotPos, 1); 
    }
    if (sign == '-')
    {
        sNotation = "-" + sNotation;
    }
    cout << sNotation;
    return 0;
}