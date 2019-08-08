#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

struct Student
{
    char name[5];
};

bool operator < (const Student & s1, const Student & s2)
{
    return strcmp(s1.name, s2.name) < 0;
}

int main()
{
    vector<Student> studentList[40004];
    int N, K, courseID, studentID, courseNum;
    char name[5];
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        Student * newStudent = new Student;
        scanf("%s %d", newStudent->name, &courseNum);
        for (int j = 1; j <= courseNum; j++)
        {
            cin >> courseID;
            studentList[courseID].push_back(*newStudent);
        } 
    }
    for (int i = 1; i <= K; i++)
    {
        sort(studentList[i].begin(), studentList[i].end());
        cout << i << " " << studentList[i].size() << endl;
        for (int j = 0; j < studentList[i].size(); j++)
        {
            printf("%s\n", studentList[i][j].name);
        }
    }
    return 0;
}