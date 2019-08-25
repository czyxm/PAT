#include<bits/stdc++.h>
using namespace std;

struct User
{
    int id, totalScore, passNum, acNum, s[6];
}users[10001];

bool compare(const int & id1, const int & id2)
{
    if (users[id1].totalScore == users[id2].totalScore)
    {
        if (users[id1].acNum == users[id2].acNum)
        {
            return id1 < id2;
        }
        return users[id1].acNum > users[id2].acNum;
    }
    return users[id1].totalScore > users[id2].totalScore;
}

int main()
{
    int N, K, M, uID, pID, score, rank;
    int fullScore[6];
    vector<int> rankList;
    cin >> N >> K >> M;
    for (int i = 1; i <= K; i++)
    {
        cin >> fullScore[i];
    }
    for (int i = 1; i <= 10000; i++)
    {
        users[i].totalScore = users[i].passNum = users[i].acNum = 0;
        for (int j = 1; j <= 5; j++)
        {
            //-2 denotes that the user has never submitted answer for this problem
            //-1 denotes that the user has submitted answer but couldn't pass the compiler
            users[i].s[j] = -2;  
        }
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> uID >> pID >> score;
        if (score > users[uID].s[pID])
        {
            if (users[uID].s[pID] < 0)
            {
                if (score >= 0)
                {
                    users[uID].passNum++;
                    users[uID].totalScore += users[uID].s[pID] = score;
                }
                else if (users[uID].s[pID] == -2)
                {
                    users[uID].s[pID] = -1;
                }
            }
            else
            {
                users[uID].totalScore -= users[uID].s[pID];
                users[uID].totalScore += users[uID].s[pID] = score;
            }
            if (score == fullScore[pID])
            {
                users[uID].acNum++;
            }
        }
    }
    for (int i = 1; i <= 10000; i++)
    {
        if (users[i].passNum > 0)
        {
            rankList.push_back(i);
        }
    }
    sort(rankList.begin(), rankList.end(), compare);
    rank = 1;
    for (int i = 0; i < rankList.size(); i++)
    {
        if (i > 0 && users[rankList[i]].totalScore < users[rankList[i - 1]].totalScore)
        {
            rank = i + 1;
        }
        cout << rank << " " << setw(5) << setfill('0') << rankList[i] << " " << users[rankList[i]].totalScore;
        for (int j = 1; j <= K; j++)
        {
            if (users[rankList[i]].s[j] >= -1)
            {
                cout << " " << max(0, users[rankList[i]].s[j]);
            }
            else
            {
                cout << " -";
            }
        }
        cout << endl;
    }
    return 0;
}