#include<bits/stdc++.h>
using namespace std;

struct Wolves
{
    int wolf1, wolf2;
    Wolves(int wolf1 = 0, int wolf2 = 0):wolf1(wolf1), wolf2(wolf2){}
    bool operator< (const Wolves & w)const
    {
        if (wolf1 == w.wolf1)
        {
            return wolf2 < w.wolf2;
        }
        return wolf1 < w.wolf1;
    }
    void operator= (const Wolves & w)
    {
        wolf1 = w.wolf1;
        wolf2 = w.wolf2;
    }
}wolf, _wolf;

int N;
vector<int> state, isLiar;

bool check()
{
    //Identity: 0 for unknown, 1 for human, -1 for wolf
    vector<int> identity(N + 1, 0);
    set<int> wolves, humen;
    for (int i = 1; i <= N; i++)
    {
        int value = state[i] * isLiar[i];
        if (identity[abs(value)] == 0)
        {
            if (value > 0)
            {
                identity[value] = 1;
                humen.insert(value);
            }
            else if (value < 0)
            {
                identity[-value] = -1;
                wolves.insert(-value);
            }
        }
        else
        {
            //Paradox
            if (identity[abs(value)] * value < 0)
            {
                return false;
            }
        }
    }
    if (wolves.size() + humen.size() < N)
    {
        int i = 1;
        while (i <= N && wolves.size() < 2)
        {
            if (identity[i] == 0)
            {
                wolves.insert(i);
            }
            i++;
        }
    }
    if (wolves.size() != 2)
    {
        return false;
    }
    auto iter = wolves.begin();
    int p1 = *iter, p2 = *(++iter);
    //At least one wolf is lying but not all the wolves are lying
    //1.All the wolves appear in the statements but only one of them is lying: 0 + 1 = -1
    //2.Only one wolf appears and it is lying: -1 * 1 = -1
    if (!(isLiar[p1] + isLiar[p2] == -1 || isLiar[p1] * isLiar[p2] == -1))
    {
        return false;
    }
    _wolf.wolf1 = p1;
    _wolf.wolf2 = p2;
    return true;
}

void Backtrack(int n, int liarNum)
{
    if (n == N + 1)
    {
        if (liarNum == 2 && check())
        {
            if (wolf.wolf1 == 0 || _wolf < wolf)
            {
                wolf = _wolf;
            }
        }
    }
    else if (n <= N)
    {
        isLiar[n] = 1;
        Backtrack(n + 1, liarNum);
        if (liarNum < 2)
        {
            isLiar[n] = -1;
            Backtrack(n + 1, liarNum + 1);
        }
    }
}

int main()
{
    cin >> N;
    state.resize(N + 1);
    isLiar.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> state[i];
    }
    Backtrack(1, 0);
    if (wolf.wolf1 == 0)
    {
        cout << "No Solution";
    }
    else
    {
        cout << wolf.wolf1 << " " << wolf.wolf2;
    }
    return 0;
}