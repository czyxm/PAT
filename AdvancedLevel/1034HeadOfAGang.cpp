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