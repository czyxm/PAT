#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct Node{
    int address;
    int key;
    int next;
}*pNode;

bool compare(const pNode & n1, const pNode & n2)
{
    return n1->key < n2->key;
}

int main()
{
    pNode list[100000] = {nullptr};
    vector<pNode> node;
    int N, headAddress;
    cin >> N >> headAddress;
    for (int i = 1; i <= N; i++)
    {
        pNode newNode = new Node;
        cin >> newNode->address >> newNode->key >> newNode->next;
        list[newNode->address] = newNode;
    }
    if (headAddress == -1)
    {
        cout << "0 -1" << endl;
        return 0;
    }
    while (N != 0 && headAddress != -1)
    {
        if (list[headAddress] != nullptr)
        {
            node.push_back(list[headAddress]);
            headAddress = list[headAddress]->next;
        }   
        else  //Not a valid linked list
        {
            node.clear();
            break;
        }
    }
    if (node.size() == 0)
    {
        cout << "0 " << setw(5) << setfill('0') << headAddress << endl;
    }
    else
    {
        
        sort(node.begin(), node.end(), compare);
        cout << node.size() << " " << setw(5) << setfill('0') << node[0]->address << endl;
        for (int i = 0; i < node.size(); i++)
        {
            cout << setw(5) << setfill('0') << node[i]->address << " " << node[i]->key << " ";
            if (i == node.size() - 1)
            {
                cout << "-1" << endl;
            }
            else
            {
                cout << setw(5) << setfill('0') << node[i + 1]->address << endl;
            }
        }
    }
    return 0;
}