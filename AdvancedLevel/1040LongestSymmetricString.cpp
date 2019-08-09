#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    bool isSymmetric;
    int maxLength = 1;
    getline(cin, str);
    for (int i = 0; i < str.size() - 1; i++)
    {
        for (int j = i + 1; j < str.size(); j++)
        {
            if (j - i + 1 > maxLength)
            {
                isSymmetric = true;
                for (int p = i, q = j; p < q; p++, q--)
                {
                    if (str[p] != str[q])
                    {
                        isSymmetric = false;
                        break;
                    }
                }
                if (isSymmetric)
                {
                    maxLength = j - i + 1;
                }
            }
        }
    }
    cout << maxLength;
    return 0;
}