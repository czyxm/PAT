#include<bits/stdc++.h>
using namespace std;

vector<bool> worned(37, false);

int _hash(char key)
{
    if ('A' <= key && key <= 'Z')
    {
        return key - 'A' + 11;
    }
    if ('0' <= key && key <= '9')
    {
        return key - '0' + 1;
    }
    return 0;
}

int main()
{
    int i = 0, j = 0, index;
    string supposedStr, typedStr;
    cin >> supposedStr >> typedStr;
    while (i < supposedStr.size())
    {
        supposedStr[i] = toupper(supposedStr[i]);
        typedStr[j] = toupper(typedStr[j]);
        if (supposedStr[i] == typedStr[j])
        {
            i++;
            j++;
        }
        else
        {
            index = _hash(supposedStr[i]);
            if (!worned[index])
            {
                worned[index] = true;
                cout << supposedStr[i];
            }
            i++;
        }
    }
    return 0;
}