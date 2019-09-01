#include<bits/stdc++.h>
using namespace std;

struct People
{
    int rank;
    bool valid;
    bool checked;
    People ()
    {
        valid = checked = false;
    }
}people[10001];

bool isPrime(int n)
{
    if (n == 1)
    {
        return false;
    }
    if (n == 2)
    {
        return true;
    }
    int m = (int)sqrt(n);
    for (int i = 2; i <= m; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int N, K, id;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> id;
        people[id].rank = i;
        people[id].valid = true;
    }
    cin >> K;
    for (int i = 1; i <= K; i++)
    {
        cin >> id;
        cout << setw(4) << setfill('0') << id << ": ";
        if (people[id].valid)
        {
            if (people[id].checked)
            {
                cout << "Checked";
            }
            else
            {
                people[id].checked = true;
                if (people[id].rank == 1)
                {
                    cout << "Mystery Award";
                }
                else if (isPrime(people[id].rank))
                {
                    cout << "Minion";
                }
                else
                {
                    cout << "Chocolate";
                }
            }
        }
        else
        {
            cout << "Are you kidding?";
        }
        cout << endl;
    }
    return 0;
}