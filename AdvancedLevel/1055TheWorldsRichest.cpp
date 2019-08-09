#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
//Structure node for people
typedef struct PeopleNode
{
    char name[9];
    int age;
    int net_worth;
}*PNode;
//Compare function for sorting people
bool compare(const PNode & p1, const PNode p2)
{
    if (p1->net_worth == p2->net_worth)
    {
        if (p1->age == p2->age)
        {
            return strcmp(p1->name, p2->name) < 0;
        }
        return p1->age < p2->age;
    }
    return p1->net_worth > p2->net_worth;
}

int main()
{
    vector<PNode> people;
    int start[201], end[201];
    int N, K, M, minAge, maxAge, front, rear, count;
    cin >> N >> K;
    people.resize(N);
    for (int i = 0; i <= 200; i++)
    {
        start[i] = end[i] = -1;
    }
    for (int i = 0; i < N; i++)
    {
        people[i] = new PeopleNode;
        scanf("%s %d %d", people[i]->name, &people[i]->age, &people[i]->net_worth);
    }
    sort(people.begin(), people.end(), compare);
    //Find the start and end position for each age of given people
    for (int i = 0; i < N; i++)
    {
        if (start[people[i]->age] == -1)
        {
            start[people[i]->age] = i;
        }
        end[people[i]->age] = i;
    }
    for (int i = 1; i <= K; i++)
    {
        cin >> M >> minAge >> maxAge;
        cout << "Case #" << i << ":" << endl;
        front = N - 1;
        rear = 0;
        //Find the smallest position of start and largest position of end
        //Determine the search scope
        for (int j = minAge; j <= maxAge; j++)
        {
            if (start[j] == -1)
            {
                continue;
            }
            if (start[j] < front)
            {
                front = start[j];
            }
            if (end[j] > rear)
            {
                rear = end[j];
            }
        }
        count = 0;
        for (int j = front; j <= rear && count < M; j++)
        {
            if (minAge <= people[j]->age && people[j]->age <= maxAge)
            {
                count++;
                cout << people[j]->name << " " << people[j]->age << " " << people[j]->net_worth << endl;
            }
        }
        if (count == 0)
        {
            cout << "None" << endl;
        }
    }
    return 0;
}