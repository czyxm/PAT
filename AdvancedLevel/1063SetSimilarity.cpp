#include<iostream>
#include<iomanip>
#include<vector>
#include<set>
using namespace std;

int main()
{
    vector< set<long> > sets;
    long number;
    int N, M, K, set1, set2, Nc, Nt;
    cin >> N;
    sets.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> M;     
        for (int j = 1; j <= M; j++)
        {
            cin >> number;
            sets[i].insert(number);
        }
    }
    cin >> K;
    for (int i = 1; i <= K; i++)
    {
        cin >> set1 >> set2;
        set1--;
        set2--;
        Nc = 0;
        auto begin = sets[set1].begin(), end = sets[set1].end();
        while (begin != end)
        {
            if (sets[set2].find(*begin) != sets[set2].end())
            {
                Nc++;
            }
            begin++;
        }
        Nt = sets[set1].size() + sets[set2].size() - Nc;
        cout << fixed << setprecision(1) << Nc * 1.0 / Nt * 100 << "%" << endl;
    }
    return 0;
}