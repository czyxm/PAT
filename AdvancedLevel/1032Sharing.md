# Sharing
To store English words, one method is to use linked lists and store a word letter by letter. To save some space, we may let the words share the same sublist if they share the same suffix. For example, loading and being are stored as showed in Figure 1.


![](../img/1032.jpg)


Figure 1
You are supposed to find the starting position of the common suffix (e.g. the position of i in Figure 1).
### Input Specification:
Each input file contains one test case. For each case, the first line contains two addresses of nodes and a positive N (<=10^5), where the two addresses are the addresses of the first nodes of the two words, and N is the total number of nodes. The address of a node is a 5-digit positive integer, and NULL is represented by ?1.
Then N lines follow, each describes a node in the format:
```
Address Data Next
```
where Address is the position of the node, Data is the letter contained by this node which is an English letter chosen from { a-z, A-Z }, and Next is the position of the next node.
### Output Specification:
For each case, simply output the 5-digit starting position of the common suffix. If the two words have no common suffix, output -1 instead.
### Sample Input 1:
```in
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010
```
### Sample Output 1:
```out
67890
```
### Sample Input 2:
```in
00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1
```
### Sample Output 2:
```out
-1
```
### Solution
#### Method1
Just record all the next addresses. Result is:
* The start addresses of two words are the same
* One of the start addresses appears in the next addresses
* There is an address appears twice in the next addresses

Unfortunately, failed to pass the last point :(
```C++
#include<iostream>
#include<set>
#include<string>
using namespace std;

int main()
{
    set<string> nextPosition;
    string startStr1, startStr2, str, resStr = "-1";
    int N;
    cin >> startStr1 >> startStr2 >> N;
    if (startStr1 == startStr2)
    {
        resStr = startStr1;
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> str >> str >> str;
        if (str == startStr1 || str == startStr2)
        {
            resStr = str;
        }
        if (nextPosition.find(str) == nextPosition.end())
        {
            nextPosition.insert(str);
        }
        else
        {
            resStr = str;
        }
    }
    cout << resStr;
    return 0;
}
```
#### Method2
Record the first list, and get through the second one to find the first common address.
```C++
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
        node[addr] = -2;  //Mark the node's next address as -2
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
```