#include<bits/stdc++.h>
using namespace std;

vector<int> adjacentList[100000];
int amount[100000] = {0};
double rate, totalSale = 0.0;

void DFS(int index, double price)
{
    totalSale += price * amount[index];
    price *= rate;
    for (int i = 0; i < adjacentList[index].size(); i++)
    {
        DFS(adjacentList[index][i], price);
    }
}

int main()
{
    int N, degree;
    double price;
    cin >> N >> price >> rate;
    rate = rate / 100 + 1;
    for (int i = 0; i < N; i++)
    {
        cin >> degree;
        if (degree > 0)
        {
            adjacentList[i].resize(degree);
            for (int j = 0; j < degree; j++)
            {
                cin >> adjacentList[i][j];
            }
        }
        else
        {
            cin >> amount[i];
        }
    }
    DFS(0, price);
    cout << fixed << setprecision(1) << totalSale;
    return 0;
}

/* BFS version
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, degree;
    vector< vector<int> > adjacentList;
    vector<int> amount;
    vector<double> price;
    double totalScale = 0.0, rate, initPrice;
    cin >> N >> initPrice >> rate;
    adjacentList.resize(N);
    amount.resize(N);
    price.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> degree;
        if (degree > 0)
        {
            adjacentList[i].resize(degree);
            for(int j = 0; j < degree; j++)
            {
                cin >> adjacentList[i][j];
            }
        }
        else
        {
            cin >> amount[i];
        }
    }
    //BFS
    queue<int> suppliers;
    int supplier, nextTail, tail = 0;
    suppliers.push(0);
    while (!suppliers.empty())
    {
        supplier = suppliers.front();
        suppliers.pop();
        price[supplier] = initPrice;
        if (adjacentList[supplier].empty())
        {
            totalScale += price[supplier] * amount[supplier];
        }
        for (int i = 0; i < adjacentList[supplier].size(); i++)
        {
            suppliers.push(adjacentList[supplier][i]);
            nextTail = adjacentList[supplier][i];
        }
        if (supplier == tail)
        {
            initPrice *= 1 + rate / 100;
            tail = nextTail;
        }
    }
    cout << fixed << setprecision(1) << totalScale;
    return 0;
}
*/