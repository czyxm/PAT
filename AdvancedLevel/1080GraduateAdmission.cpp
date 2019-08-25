#include<bits/stdc++.h>
using namespace std;

struct Applicant
{
    int id, Ge, Gi;
    int school[5];
}applicants[40000];

struct School
{
    int quota;
    vector<int> admission;
}schools[100];
//Rank applicants by Ge and Gi
bool compare1(const Applicant & a1, const Applicant & a2)
{
    if (a1.Ge + a1.Gi == a2.Ge + a2.Gi)
    {
        return a1.Ge > a2.Ge;
    }
    return a1.Ge + a1.Gi > a2.Ge + a2.Gi;
}
//Rank applicants in the same school by id
bool compare2(const int & index1, const int & index2)
{
    return applicants[index1].id < applicants[index2].id;
}

int main()
{
    int N, M, K, schIndex, stuIndex;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
    {
        cin >> schools[i].quota;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> applicants[i].Ge >> applicants[i].Gi;
        for (int j = 0; j < K; j++)
        {
            cin >> applicants[i].school[j];
        }
        applicants[i].id = i;
    }
    sort(applicants, applicants + N, compare1);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            schIndex = applicants[i].school[j];
            if (schools[schIndex].quota > 0)
            {
                schools[schIndex].admission.push_back(i);
                schools[schIndex].quota--;
                break;
            }
            else if (!schools[schIndex].admission.empty())
            {
                stuIndex = schools[schIndex].admission.back();
                if (applicants[i].Ge == applicants[stuIndex].Ge && applicants[i].Gi == applicants[stuIndex].Gi)
                {
                    schools[schIndex].admission.push_back(i);
                    schools[schIndex].quota--;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        sort(schools[i].admission.begin(), schools[i].admission.end(), compare2);
        for (int j = 0; j < schools[i].admission.size(); j++)
        {
            if (j != 0)
            {
                cout << " ";
            }
            cout << applicants[schools[i].admission[j]].id;
        }
        cout << endl;
    }
    return 0;
}