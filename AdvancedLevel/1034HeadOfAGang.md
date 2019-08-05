# Head of a Gang
One way that the police finds the head of a gang is to check people's phone calls. If there is a phone call between A and B, we say that A and B is related. The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. A "Gang" is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a given threthold K. In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.
### Input Specification:
Each input file contains one test case. For each case, the first line contains two positive numbers N and K (both less than or equal to 1000), the number of phone calls and the weight thredhold, respectively. Then N lines follow, each in the following format:
```
Name1 Name2 Time
```
where Name1 and Name2 are the names of people at the two ends of the call, and Time is the length of the call. A name is a string of three capital letters chosen from A-Z. A time length is a positive integer which is no more than 1000 minutes.
### Output Specification:
For each test case, first print in a line the total number of gangs. Then for each gang, print in a line the name of the head and the total number of the members. It is guaranteed that the head is unique for each gang. The output must be sorted according to the alphabetical order of the names of the heads.
### Sample Input 1:
```
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
```
### Sample Output 1:
```
2
AAA 3
GGG 3
```
### Sample Input 2:
```
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
```
### Sample Output 2:
```
0
```
### Solution
DFS to find connect components meeting the gang's condition:
* total weight > thredhod
* number of members more than 2
Notice that the graph has circle because of the characteristic of a call, thus I caculate the weight of a cluster `double`--each relation is caculated twice no matter the person has been known or not. At the end the actual total weight will be the half of the result.
Don't forget to sort the gangs by name of head alphabetically.

```C++
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct GangNode{
    int headIndex;
    int totalWeight;
    int member;
}* GNode;
//N <= 1000, thus the number of persons is at most 2000
int relation[2000][2000] = {0};
bool known[2000] = {false};
vector<GNode> gang;
vector<string> person;
//Return the index of person if find its name, otherwise return -1
int find(const string & name)
{
    for (int i = 0; i < person.size(); i++)
    {
        if (person[i] == name)
        {
            return i;
        }
    }
    return -1;
}
//Deep First Search to find connect components --> gang clusters
void DFS(int n, GNode & newGang)
{
    static int maxWeight = 0;
    known[n] = true;
    int weight = 0;
    for (int i = 0; i < person.size(); i++)
    {
        if (relation[n][i] > 0)
        {
            //Because there's circle in the graph, thus the weight of known person shold be considered as well
            //Finally the total weight is as twice as the actual weight since each relation is caculated twice
            weight += relation[n][i];
            if (!known[i])
            {
                DFS(i, newGang);
            }
        }
    }
    //Find a bigger weight and refresh the head index
    if (newGang->headIndex == -1 || weight > maxWeight)
    {
        newGang->headIndex = n;
        maxWeight = weight;
    }
    newGang->member++;
    newGang->totalWeight += weight;
}
//Compare function for sorting gang by their name alphabetically
bool compare(const GNode & g1, const GNode g2)
{
    return person[g1->headIndex] < person[g2->headIndex];
}

int main()
{
    int N, K, u, v, timeLength, index;
    string caller, callee;
    cin >> N >> K;
    //Read input
    for (int i = 1; i <= N; i++)
    {
        cin >> caller >> callee >> timeLength;
        if ((index = find(caller)) >= 0)
        {
            u = index;
        }
        else
        {
            u = person.size();
            person.push_back(caller);
        }
        if ((index = find(callee)) >= 0)
        {
            v = index;
        }
        else
        {
            v = person.size();
            person.push_back(callee);
        }
        relation[u][v] += timeLength;
        relation[v][u] += timeLength;
    }
    for (int i = 0; i < person.size(); i++)
    {
        if (!known[i])
        {
            GNode newGang = new GangNode;
            newGang->member = newGang->totalWeight = 0;
            newGang->headIndex = -1;
            DFS(i, newGang);
            //If meet the gang's condition
            if (newGang->totalWeight > 2 * K && newGang->member > 2)
            {
                gang.push_back(newGang);
            }
            else
            {
                delete newGang;
            }
        }
    }
    sort(gang.begin(), gang.end(), compare);
    cout << gang.size() << endl;
    for (int i = 0; i < gang.size(); i++)
    {
        cout << person[gang[i]->headIndex] << " " << gang[i]->member << endl;
        delete gang[i];
    }
    return 0;
}
```