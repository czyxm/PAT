#include<bits/stdc++.h>
using namespace std;

struct People
{
    int sets, area;
    vector<int> relative;
    People()
    {
        sets = area = 0;
    }
}people[10000];

struct Family
{
    vector<int> member;
    double avgArea, avgSets;
};

map<int, bool> known;
vector<Family*> family;

bool compare(const Family* f1, const Family* f2)
{
    if (f1->avgArea == f2->avgArea)
    {
        return f1->member[0] < f2->member[0];
    }
    return f1->avgArea > f2->avgArea;
}

int main()
{
    int N, id, child, father, mother, degree;
    queue<int> ids;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> id >> father >> mother;
        cin >> degree;
        for (int j = 0; j < degree; j++)
        {
            cin >> child;
            people[id].relative.push_back(child);
            people[child].relative.push_back(id);
            known.insert(pair<int, bool>(child, false));
        }
        cin >> people[id].sets >> people[id].area;
        if (father != -1)
        {
            people[id].relative.push_back(father);
            people[father].relative.push_back(id);
            known.insert(pair<int, bool>(father, false));
        }
        if (mother != -1)
        {
            people[id].relative.push_back(mother);
            people[mother].relative.push_back(id);
            known.insert(pair<int, bool>(mother, false));
        }
        known.insert(pair<int, bool>(id, false));
    }
    while (true)
    {
        id = -1;
        auto begin = known.begin(), end = known.end();
        while (begin != end)
        {
            if (!begin->second)
            {
                id = begin->first;
                break;
            }
            begin++;
        }
        if (id == -1)
        {
            break;
        }
        Family* newFamily = new Family;
        newFamily->avgArea = newFamily->avgSets = 0.000;
        ids.push(id);
        known[id] = true;
        while (!ids.empty())
        {
            id = ids.front();
            ids.pop();
            newFamily->member.push_back(id);
            newFamily->avgArea += people[id].area;
            newFamily->avgSets += people[id].sets;
            for (int i = 0; i < people[id].relative.size(); i++)
            {
                child = people[id].relative[i];
                if (!known[child])
                {
                    ids.push(child);
                    known[child] = true;
                }
            }
        }
        newFamily->avgArea /= newFamily->member.size();
        newFamily->avgSets /= newFamily->member.size();
        sort(newFamily->member.begin(), newFamily->member.end(), less<int>());
        family.push_back(newFamily);
    }
    sort(family.begin(), family.end(), compare);
    cout << family.size() << endl;
    for (int i = 0; i < family.size(); i++)
    {
        cout << setw(4) << setfill('0') << family[i]->member[0] << " " << family[i]->member.size() << " ";
        cout << fixed << setprecision(3) << family[i]->avgSets << " " << family[i]->avgArea << endl;
    }
    return 0;
}