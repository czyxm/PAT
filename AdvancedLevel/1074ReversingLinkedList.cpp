#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int address, data, next;
};

int main()
{
    vector<Node> nodes;
    vector<int> reversed;
    int N, K, startAddr, address, counter;
    cin >> startAddr >> N >> K;
    nodes.resize(100001);
    for (int i = 0; i < N; i++)
    {
        cin >> address >> nodes[address].data >> nodes[address].next;
        nodes[address].address = address;
    }
    counter = 0;
    reversed.resize(N);
    while (startAddr != -1)
    {
        reversed[counter++] = startAddr;
        startAddr = nodes[startAddr].next;
        if (counter % K == 0)
        {
            reverse(reversed.begin() + counter - K, reversed.begin() + counter);
        }
    }
    //Counter is the number of *valid* node
    for (int i = 0; i < counter; i++)
    {
        address = reversed[i];
        if (i != 0)
        {
            cout << setw(5) << setfill('0') << address << endl;
        }
        cout << setw(5) << setfill('0') << address << " " << nodes[address].data << " ";
    }
    cout << -1 << endl;
    return 0;
}