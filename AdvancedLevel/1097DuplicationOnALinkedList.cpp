#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int address, next, key;
};

int main()
{
    int N, headAddr, address;
    bool exist[10001] = {false};
    vector<Node> nodes;
    vector<Node*> leftNodes, dupliNodes;
    cin >> headAddr >> N;
    nodes.resize(100000);
    for (int i = 1; i <= N; i++)
    {
        cin >> address >> nodes[address].key >> nodes[address].next;
        nodes[address].address = address;
    }
    while (headAddr != -1)
    {
        if (exist[abs(nodes[headAddr].key)])
        {
            dupliNodes.push_back(&nodes[headAddr]);
        }
        else
        {
            leftNodes.push_back(&nodes[headAddr]);
            exist[abs(nodes[headAddr].key)] = true;
        }
        headAddr = nodes[headAddr].next;
    }
    for (int i = 0; i < leftNodes.size(); i++)
    {
        if (i != 0)
        {
            cout << setw(5) << setfill('0') << leftNodes[i]->address << endl;
        }
        cout << setw(5) << setfill('0') << leftNodes[i]->address << " " << leftNodes[i]->key << " ";
    }
    if (leftNodes.size() > 0)
    {
        cout << "-1" << endl;
    }
    for (int i = 0; i < dupliNodes.size(); i++)
    {
        if (i != 0)
        {
            cout << setw(5) << setfill('0') << dupliNodes[i]->address << endl;
        }
        cout << setw(5) << setfill('0') << dupliNodes[i]->address << " " << dupliNodes[i]->key << " ";
    }
    if (dupliNodes.size() > 0)
    {
        cout << "-1" << endl;
    }
    return 0;
}