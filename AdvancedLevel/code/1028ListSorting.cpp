#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct RecordNode
{
    string ID;
    int IDValue;
    int score;
    string name;
}*RNode;

bool compare1(const RNode & r1, const RNode & r2)
{
    return r1->IDValue < r2->IDValue;
}

bool compare2(const RNode & r1, const RNode & r2)
{
    return r1->name < r2->name || (r1->name == r2->name && r1->IDValue < r2->IDValue);
}

bool compare3(const RNode & r1, const RNode & r2)
{
    return r1->score < r2->score || (r1->score == r2->score && r1->IDValue < r2->IDValue);
}

int main()
{
    int N, C;
    vector<RNode> records;
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        RNode newRecord = new RecordNode;
        cin >> newRecord->ID >> newRecord->name >> newRecord->score;
        newRecord->IDValue = stoi(newRecord->ID);
        records.push_back(newRecord);
    }
    switch (C)
    {
        case 1 : sort(records.begin(), records.end(), compare1); break;
        case 2 : sort(records.begin(), records.end(), compare2); break;
        case 3 : sort(records.begin(), records.end(), compare3); break;
    }
    for (int i = 0; i < N; i++)
    {
        cout << records[i]->ID << " " << records[i]->name << " " << records[i]->score << endl;
    }
    return 0;
}