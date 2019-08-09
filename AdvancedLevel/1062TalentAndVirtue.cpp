#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct PeopleNode
{
    int talent, virtue, _class;
    char ID[9];
}*PNode;

bool compare(const PNode & p1, const PNode & p2)
{
    if (p1->_class == p2->_class)
    {
        if (p1->virtue + p1->talent == p2->virtue + p2->talent)
        {
            if (p1->virtue == p2->virtue)
            {
                return strcmp(p1->ID, p2->ID) < 0;
            }
            return p1->virtue > p2->virtue;
        }
        return p1->virtue + p1->talent > p2->virtue + p2->talent;
    }
    return p1->_class < p2->_class;
}

int main()
{
    vector<PNode> people;
    int N, L, H;
    cin >> N >> L >> H;
    for (int i = 0; i < N; i++)
    {
        PNode newPeople = new PeopleNode;
        cin >> newPeople->ID >> newPeople->virtue >> newPeople->talent;
        if (newPeople->virtue >= L && newPeople->talent >= L)
        {
            if (newPeople->virtue >= H)
            {
                if (newPeople->talent >= H)
                    newPeople->_class = 1;
                else
                    newPeople->_class = 2;
            }
            else
            {
                if (newPeople->virtue >= newPeople->talent)
                    newPeople->_class = 3;
                else
                    newPeople->_class = 4;
            }
            people.push_back(newPeople);
        }
        else
        {
            delete newPeople;
        }
    }
    sort(people.begin(), people.end(), compare);
    cout << people.size() << endl;
    for (int i = 0; i < people.size(); i++)
    {
        cout << people[i]->ID << " " << people[i]->virtue << " " << people[i]->talent << endl;
    }
    return 0;
}