#include<iostream>
#include<string>
#include<queue>
using namespace std;
//Structure node of studnets
typedef struct StudentNode
{
    string name;
    string ID;
    int grade;
}SNode;
//Overwrite the operator <
bool operator < (const StudentNode & s1, const StudentNode & s2)
{
    return s1.grade < s2.grade;
}
//Overwrite the operator >
bool operator > (const StudentNode & s1, const StudentNode & s2)
{
    return s1.grade > s2.grade;
}

int main()
{
    int N;
    char gender;
    priority_queue<SNode, vector<SNode>, less<vector<SNode>::value_type> > female;//max heap
    priority_queue<SNode, vector<SNode>, greater<vector<SNode>::value_type> > male;//min heap
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        SNode * newStudent = new StudentNode;
        cin >> newStudent->name >> gender >> newStudent->ID >> newStudent->grade;
        if (gender == 'F')
        {
            female.push(*newStudent);
        }
        else
        {
            male.push(*newStudent);
        }
    }
    if (female.size() <= 0)
    {
        cout << "Absent" << endl;
    }
    else
    {
        cout << female.top().name << " " << female.top().ID << endl;
    }
    if (male.size() <= 0)
    {
        cout << "Absent" << endl;
    }
    else
    {
        cout << male.top().name << " " << male.top().ID << endl;
    }
    if (female.size() <= 0 || male.size() <= 0)
    {
        cout << "NA" << endl;
    }
    else
    {
        cout << female.top().grade - male.top().grade << endl;
    }
    return 0;
}