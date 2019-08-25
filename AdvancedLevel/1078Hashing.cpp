#include<bits/stdc++.h>
using namespace std;

bool isPrime(int key)
{
    int half = key >> 1;
    if (key == 1)
    {
        return false;
    }
    else if (key == 2)
    {
        return true;
    }
    for (int i = 2; i <= half; i++)
    {
        if (key % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int MSize, N, key, pos;
    cin >> MSize >> N;
    while (!isPrime(MSize))
    {
        MSize++;
    }
    vector<int> hashTable(MSize, -1);
    vector<int> position;
    for (int i = 1; i <= N; i++)
    {
        cin >> key;
        int j = 1;
        pos = key % MSize;
        do
        {
            if (hashTable[pos] < 0)
            {
                hashTable[pos] = key;
                position.push_back(pos);
                break;
            }
            //Quadratic probing
            pos = (key + j * j) % MSize;
            j++;
        }while (pos != key % MSize); //Back to the initial position again
        if (hashTable[pos] != key)
        {
            position.push_back(-1);
        }
    }
    for (int i = 0; i < position.size(); i++)
    {
        if (i != 0)
        {
            cout << " ";
        }
        if (position[i] >= 0)
        {
            cout << position[i];
        }
        else
        {
            cout << "-";
        }
    }
    return 0;
}