#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    map<int, int>rank;
    vector<int> stripe, length;
    int N, M, L, color, maxLength;
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> color;
        rank.insert(pair<int, int>(color, i));
    }
    cin >> L;
    for (int i = 1; i <= L; i++)
    {
        cin >> color;
        auto iter = rank.find(color);
        if (iter!= rank.end())
        {
            stripe.push_back(iter->second);
        }
    }
    length.resize(stripe.size());
    maxLength = 1;
    for (int i = 0; i < stripe.size(); i++)
    {
        int j = i - 1;
        while (j >= 0 && stripe[j] > stripe[i]) {j--;}
        if (j < 0)
        {
            length[i] = 1;
        }
        else
        {
            length[i] = length[j] + 1;
            if (length[i] > maxLength)
            {
                maxLength = length[i];
            }
        }
    }
    cout << maxLength;
    return 0;
}