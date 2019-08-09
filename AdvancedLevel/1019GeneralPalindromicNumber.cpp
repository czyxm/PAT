#include<iostream>
#include<vector>
using namespace std;

int main()
{
    long long N, R;
    int flag = true;
    vector<long long> digit;
    cin >> N >> R;
    if (N == 0)
    {
        cout << "Yes" << endl << "0";
        return 0;
    }
    while (N > 0)
    {
        digit.push_back(N % R);
        N /= R;
    }
    for (int i = 0, j = digit.size() - 1; i < j; i++, j--)
    {
        if (digit[i] != digit[j])
        {
            cout << "No" << endl;
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "Yes" << endl;
    }
    for (int i = digit.size() - 1; i >= 0; i--)
    {
        cout << digit[i];
        if (i > 0)
        {
            cout << " ";
        }
    }
    return 0;
}