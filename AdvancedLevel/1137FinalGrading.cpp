#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

class Student
{
public:
    int Gp, Gm, Gf;
    char ID[21];
    Student(string ID, int Gp = -1, int Gm = -1, int Gf = -1):Gp(Gp),Gm(Gm),Gf(Gf)
    {
        strcpy(this->ID, ID.c_str());
    }
    int G()const
    {
        return (Gm > Gf ? int(Gm * 0.4 + Gf * 0.6 + 0.5) : Gf);
    }
};

bool compare(Student* s1, Student* s2)
{
    int G1 = s1->G(), G2 = s2->G();
    if (G1 == G2)
    {
        return strcmp(s1->ID, s2->ID) < 0;
    }
    return G1 > G2;
}

vector<Student*> student;
map<string, Student*> reflect;

int main()
{
    int P, M, N, Gp, Gm, Gf, G;
    string ID;
    cin >> P >> M >> N;
    for (int i = 1; i <= P; i++)
    {
        cin >> ID >> Gp;
        if (Gp >= 200)
        {
            Student* stu = new Student(ID, Gp);
            student.push_back(stu);
            reflect.insert(pair<string, Student*>(ID, stu));
        }
    }
    map<string, Student*>::iterator iter;
    for (int i = 1; i <= M; i++)
    {
        cin >> ID >> Gm;
        iter = reflect.find(ID);
        if (iter != reflect.end())
        {
            iter->second->Gm = Gm;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> ID >> Gf;
        iter = reflect.find(ID);
        if (iter != reflect.end())
        {
            iter->second->Gf = Gf;
        }
    }
    sort(student.begin(), student.end(), compare);
    for (int i = 0; i < student.size(); i++)
    {
        G = student[i]->G();
        if (G >= 60)
        {
            cout << student[i]->ID << " " << student[i]->Gp << " " << student[i]->Gm << " " << student[i]->Gf << " " << G << endl;
        }
    }
    return 0;
}