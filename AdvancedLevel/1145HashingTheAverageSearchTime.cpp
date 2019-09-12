#include<bits/stdc++.h>
using namespace std;

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

bool insert(int num, int MSize, vector<int> & hashTable)
{
    int index = num % MSize, i = 1;
    while (hashTable[index] > 0)
    {
        index = (num + i * i) % MSize;
        i++;
        if (index == num % MSize)
        {
            return false;
        }
    }
    hashTable[index] = num;
    return true;
}

int find(int num, int MSize, vector<int> & hashTable)
{
    int index = num % MSize, i = 1;
    while (hashTable[index] != num && hashTable[index] != 0)
    {
        index = (num + i * i) % MSize;
        i++;
        if (index == num % MSize)
        {
            break;
        }
    }
    return i;
}

int main()
{
    int MSize, N, M, num, cost = 0;
    cin >> MSize >> N >> M;
    while (!isPrime(MSize))
    {
        MSize++;
    }
    vector<int> hashTable(MSize, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        if (!insert(num, MSize, hashTable))
        {
            cout << num << " cannot be inserted." << endl;
        }
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> num;
        cost += find(num, MSize, hashTable);
    }
    cout << fixed << setprecision(1) << (float)cost / M;
    return 0;
}