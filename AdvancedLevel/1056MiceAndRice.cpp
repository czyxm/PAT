#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> weight, order1, order2, rank;
    int Np, Ng, _rank, winner;
    cin >> Np >> Ng;
    weight.resize(Np);
    order1.resize(Np);
    rank.resize(Np);
    for (int i = 0; i < Np; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < Np; i++)
    {
        cin >> order1[i];
    }
    while (order1.size() > 1)
    {
        //Caculate the rank of losers
        _rank = (int)ceil(order1.size() * 1.0 / Ng ) + 1;
        for (int i = 0; i < order1.size(); i += Ng)
        {
            winner = order1[i];
            for (int j = i + 1; j < order1.size() && j < i + Ng; j++)
            {
                if (weight[winner] < weight[order1[j]])
                {
                    rank[winner] = _rank;
                    winner = order1[j];
                }
                else
                {
                    rank[order1[j]] = _rank;
                }
            }
            order2.push_back(winner);
        }
        order1 = order2;
        order2.clear();
    }
    //The final winner
    rank[order1[0]] = 1;
    for (int i = 0; i < Np; i++)
    {
        cout << rank[i];
        if (i < Np - 1)
        {
            cout << " ";
        }
    }
    return 0;
}