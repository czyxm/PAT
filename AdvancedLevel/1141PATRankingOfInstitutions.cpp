#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

struct Institution
{
    int rank, scoreA, scoreB, scoreT, TWS, Ns;
    char code[7];
    Institution(const string & code = "")
    :scoreA(0), scoreB(0), scoreT(0), Ns(0)
    {
        strcpy(this->code, code.c_str());
    }
    bool operator < (const Institution & ins)const
    {
        if (TWS == ins.TWS)
        {
            if (Ns == ins.Ns)
            {
                return strcmp(code, ins.code) < 0;
            }
            return Ns < ins.Ns;
        }
        return TWS > ins.TWS;
    }
};

vector<Institution> institution;

int main()
{
    unordered_map<string, int> index;
    int N, score, rank = 1;
    string ID, code;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> ID >> score >> code;
        transform(code.begin(), code.end(), code.begin(), ::tolower);
        auto iter = index.find(code);
        if (iter == index.end())
        {
            index.insert(pair<string, int>(code, index.size()));
            institution.push_back(Institution(code));
            iter = index.find(code);
        }
        switch (ID[0])
        {
            case 'T' : institution[iter->second].scoreT += score; break;
            case 'A' : institution[iter->second].scoreA += score; break;
            case 'B' : institution[iter->second].scoreB += score; break;
        }
        institution[iter->second].Ns++;
    }
    for (int i = 0; i < institution.size(); i++)
    {
        institution[i].TWS = int(institution[i].scoreB / 1.5 + institution[i].scoreA + institution[i].scoreT * 1.5);
    }
    sort(institution.begin(), institution.end());
    cout << institution.size() << endl;
    cout << "1 " << institution[0].code << " " << institution[0].TWS << " " << institution[0].Ns << endl;
    for (int i = 1; i < institution.size(); i++)
    {
        if (institution[i].TWS != institution[i - 1].TWS)
        {
            rank = i + 1;
        }
        cout << rank << " " << institution[i].code << " " << institution[i].TWS << " " << institution[i].Ns << endl;
    }
    return 0;
}