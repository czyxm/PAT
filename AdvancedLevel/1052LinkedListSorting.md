# Linked List Dorting
A linked list consists of a series of structures, which are not necessarily adjacent in memory. We assume that each structure contains an integer key and a Next pointer to the next structure. Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.
### Input Specification:
Each input file contains one test case. For each case, the first line contains a positive N (<10^5) and an address of the head node, where N is the total number of nodes in memory and the address of a node is a 5-digit positive integer. NULL is represented by ?1.
Then N lines follow, each describes a node in the format:
```
Address Key Next
```
where Address is the address of the node in memory, Key is an integer in [?10^5,10^5], and Next is the address of the next node. It is guaranteed that all the keys are distinct and there is no cycle in the linked list starting from the head node.
### Output Specification:
For each test case, the output format is the same as that of the input, where N is the total number of nodes in the list and all the nodes must be sorted order.
### Sample Input:
```
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345
```
### Sample Output:
```
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
```
### Solution
Take care of several points:
* Head address = -1
* There's no valid linked list (It's impossible to reach -1 from head address)
* List is not unique

Oh hu~

```C++
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
```