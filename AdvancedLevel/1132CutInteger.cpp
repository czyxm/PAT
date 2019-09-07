#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    int half;
    unsigned long long int N, A, B, Z;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> str;
        half = str.size() >> 1;
        Z = stoull(str);
        A = stoull(str.substr(0, half));
        B = stoull(str.substr(half, half));
        if (B == 0 || Z % (A * B) != 0)
        {
            cout << "No";
        }
        else
        {
            cout << "Yes";
        }
        cout << endl;
    }
    return 0;
}