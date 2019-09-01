#include<bits/stdc++.h>
using namespace std;

int _hash(char ch)
{
    if (isdigit(ch))
    {
        return ch - '0';
    }
    if ('a' <= ch && ch <= 'z')
    {
        return ch - 'a' + 10;
    }
    return 36;
}

int main()
{
    int k, index, count[37];
    bool stucked[37];
    string text, stuckedKeys, originalStr;
    cin >> k >> text;
    for (int i = 0; i < 37; i++)
    {
        count[i] = 0;
        stucked[i] = true;
    }
    count[_hash(text[0])] = 1;
    for (int i = 1; i < text.size(); i++)
    {
        if (text[i] != text[i - 1])
        {
            index = _hash(text[i - 1]);
            if (count[index] % k != 0)
            {
                stucked[index] = false;
            }
            count[index] = 0;
        }
        count[_hash(text[i])]++;
    }
    index = _hash(text[text.size() - 1]);
    if (count[index] % k != 0)
    {
        stucked[index] = false;
    }
    for (int i = 0; i < text.size(); i++)
    {
        index = _hash(text[i]);
        originalStr.push_back(text[i]);
        if (stucked[index])
        {
            if (stuckedKeys.find(text[i]) == string::npos)
            {
                stuckedKeys.push_back(text[i]);
            }
            i += k - 1;
        }
    }
    cout << stuckedKeys << endl << originalStr << endl;
    return 0;
}