#include<bits/stdc++.h>
using namespace std;

//TLE!!!
// int _next[100000];
// int _key[100000];
unordered_map<int, int> _next, _key;

void display(vector<int> & list)
{
    static int count = 0;
    for (int i = 0; i < list.size(); i++)
    {
        if (count != 0)
        {
            cout << setw(5) << setfill('0') << list[i] << endl;
        }
        cout << setw(5) << setfill('0') << list[i] << " " << _key[list[i]] << " ";
        count++;
    }
}

int main()
{
    vector<int> negative, zeroToK, remainder;
    int N, K, headAddr, addr;
    cin >> headAddr >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> addr >> _key[addr] >> _next[addr];
    }
    while (headAddr != -1)
    {
        if (_key[headAddr] < 0)
        {
            negative.push_back(headAddr);
        }
        else if (_key[headAddr] <= K)
        {
            zeroToK.push_back(headAddr);
        }
        else
        {
            remainder.push_back(headAddr);
        }
        headAddr = _next[headAddr];
    }
    display(negative);
    display(zeroToK);
    display(remainder);
    cout << "-1" << endl;
    return 0;
}