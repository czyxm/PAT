#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

struct Mooncake
{
    float amount, price;
};

bool compare(const Mooncake & m1, const Mooncake & m2)
{
    if (m1.price / m1.amount > m2.price / m2.amount)
    {
        return true;
    }
    return false;
}

int main()
{
    int N, D;
    float profit = 0;
    vector<Mooncake> mooncakes;
    cin >> N >> D;
    mooncakes.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> mooncakes[i].amount;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> mooncakes[i].price;
    }
    sort(mooncakes.begin(), mooncakes.end(), compare);
    auto iter = mooncakes.begin();
    while (D > 0 && iter != mooncakes.end())
    {
        if (iter->amount <= D)
        {
            profit += iter->price;
            D -= iter->amount;
        }
        else
        {
            profit += iter->price * D / iter->amount;
            D = 0;
        }
        iter++;
    }
    cout << fixed << setprecision(2) << profit << endl;
    return 0;
}