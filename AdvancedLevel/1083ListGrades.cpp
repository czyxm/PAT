#include<bits/stdc++.h>
using namespace std;

struct Student
{
    string name, id;
    int grade;
};

vector<Student> students;

bool compare(const int & index1, const int & index2)
{
    return students[index1].grade > students[index2].grade;
}

int main()
{
    int N, min, max;
    vector<int> list;
    cin >> N;
    students.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> students[i].name >> students[i].id >> students[i].grade;
    }
    cin >> min >> max;
    for (int i = 0; i < N; i++)
    {
        if (min <= students[i].grade && students[i].grade <= max)
        {
            list.push_back(i);
        }
    }
    if (list.empty())
    {
        cout << "NONE";
    }
    else
    {
        sort(list.begin(), list.end(), compare);
        for (int i = 0; i < list.size(); i++)
        {
            cout << students[list[i]].name << " " << students[list[i]].id << endl;
        }
    }
    return 0;
}