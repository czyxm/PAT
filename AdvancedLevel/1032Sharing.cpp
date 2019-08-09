#include<iostream>
#include<iomanip>
#include<map>
using namespace std;

int main()
{
    int N;
    bool * known;
    char ch;
    int startAddr1, startAddr2, addr, next;
    map<int, int> node;    
    cin >> startAddr1 >> startAddr2 >> N;
    known = new bool [N];
    for (int i = 1; i <= N; i++)
    {
        known[i] = false;
        cin >> addr >> ch >> next;
        node.insert(pair<int, int>(addr, next));
    }
    addr = startAddr1;
    while (addr != -1)
    {
        next = node[addr];
        node[addr] = -2;
        addr = next;
    }
    addr = startAddr2;
    while (addr != -1)
    {
        if (node[addr] == -2)
        {
            cout << setw(5) << setfill('0') << addr;
            break;
        }
        addr = node[addr];
    }
    if (addr == -1)
    {
        cout << "-1";
    }
    return 0;
}