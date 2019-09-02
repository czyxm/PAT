#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, id1, id2;
    vector<bool> present(100001, false);
    vector<int> guest, damnSingle, spouse(100001, -1);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> id1 >> id2;
        spouse[id1] = id2;
        spouse[id2] = id1;
    }
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> id1;
        present[id1] = true;
        if (spouse[id1] < 0)
        {
            spouse[id1] = 100000;
        }
        guest.push_back(id1);
    }
    for (int i = 0; i < N; i++)
    {
        if (!present[spouse[guest[i]]])
        {
            damnSingle.push_back(guest[i]);
        }
    }
    sort(damnSingle.begin(), damnSingle.end(), less<int>());
    cout << damnSingle.size() << endl;
    for (int i = 0; i < damnSingle.size(); i++)
    {
        if (i != 0)
        {
            cout << " ";
        }
        cout << setw(5) << setfill('0') <<  damnSingle[i];
    }
    return 0;
}