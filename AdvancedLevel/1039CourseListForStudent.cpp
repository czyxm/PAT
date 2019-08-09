#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
    map<int, int> student;
    map<int, int>::iterator iter;
    priority_queue<int, vector<int>, greater<vector<int>::value_type> > courseList[200000];
    int N, K, courseID, studentID, courseNum, stuNum = 0;
    string name;
    cin >> N >> K;
    for (int i = 1; i <= K; i++)
    {
        cin >> courseID >> courseNum;
        for (int j = 1; j <= courseNum; j++)
        {
            cin >> name;
            //Map the name of student to a int variable for faster sort and search
            studentID = (name[0] - 'A') * 100000 + (name[1] - 'A') * 1000 + (name[2] - 'A') * 10 + name[3] - '0';
            iter = student.find(studentID);
            if (iter == student.end())  //A new student
            {
                courseList[stuNum].push(courseID);
                student.insert(pair<int, int>(studentID, stuNum++));
            }
            else  //A known student
            {
                courseList[iter->second].push(courseID);
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> name;
        studentID = (name[0] - 'A') * 100000 + (name[1] - 'A') * 1000 + (name[2] - 'A') * 10 + name[3] - '0';
        iter = student.find(studentID);
        if (iter == student.end())
        {
            cout << name << " 0";
        }
        else
        {
            cout << name << " " << courseList[iter->second].size();
            while (courseList[iter->second].size() > 0)
            {
                cout << " " << courseList[iter->second].top();
                courseList[iter->second].pop();
            }
        }
        cout << endl;
    }
    return 0;
}