#include<bits/stdc++.h>
using namespace std;

struct Player
{
    int arriveTime, serveTime, playTime, isVIP;
    bool known;
    bool operator< (const Player & p)const
    {
        return arriveTime < p.arriveTime;
    }
};
struct Table
{
    int serveNumber, spareTime, isVIP;
    Table():serveNumber(0), spareTime(8 * 3600), isVIP(0){}
};

vector<Player> player;
vector<Table> table;
vector<int> res;

int toSeconds(const string & str)
{
    return stoi(str.substr(0, 2)) * 3600 + stoi(str.substr(3, 2)) * 60 + stoi(str.substr(6, 2));
}

int main()
{
    int N, K, M, tIndex, pIndex, index = 0, vipTableIndex;
    string str;
    cin >> N;
    player.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> str >> player[i].playTime >> player[i].isVIP;
        player[i].arriveTime = toSeconds(str);
        if (player[i].playTime > 120)
        {
            player[i].playTime = 120;
        }
        player[i].playTime *= 60;
        player[i].known = false;
    }
    sort(player.begin(), player.end());
    cin >> K >> M;
    table.resize(K + 1);
    for (int i = 1; i <= M; i++)
    {
        cin >> tIndex;
        table[tIndex].isVIP = 1;
    }
    while (index < player.size())
    {
        tIndex = vipTableIndex = 0;
        pIndex = index;
        bool found = false;
        //The next player comes when there are some spare tables
        for (int i = 1; i <= K; i++)
        {
            if (table[i].spareTime <= player[index].arriveTime)
            {
                if (!found)
                {
                    tIndex = i;
                    found = true;
                }
                if (table[i].isVIP == 1)
                {
                    vipTableIndex = i;
                    break;
                }
            }
        }
        //The next player comes when there is no spare table
        if (tIndex == 0)
        {
            tIndex = 1;
            for (int i = 2; i <= K; i++)
            {
                if (table[i].spareTime < table[tIndex].spareTime)
                {
                    tIndex = i;
                }
            }
            for (int i = 1; i <= K; i++)
            {
                if (table[i].spareTime == table[tIndex].spareTime && table[i].isVIP == 1)
                {
                    vipTableIndex = i;
                    break;
                }
            }
        }
        //Find next vip player in the queue
        if (vipTableIndex > 0)
        {
            for (int i = index; i < N && player[i].arriveTime <= table[tIndex].spareTime; i++)
            {
                if (!player[i].known && player[i].isVIP == 1)
                {
                    pIndex = i;
                    break;
                }
            }
        }
        if (player[pIndex].isVIP == 1 && vipTableIndex > 0)
        {
            tIndex = vipTableIndex;
        }
        if (player[pIndex].arriveTime <= table[tIndex].spareTime)
        {
            player[pIndex].serveTime = table[tIndex].spareTime;
        }
        else
        {
            player[pIndex].serveTime = player[pIndex].arriveTime;
        }
        if (player[pIndex].serveTime < 21 * 3600)
        {
            res.push_back(pIndex);
        }
        else
        {
            break;
        }
        player[pIndex].known = true;
        table[tIndex].serveNumber++;
        table[tIndex].spareTime = player[pIndex].serveTime + player[pIndex].playTime;
        while (player[index].known)
        {
            index++;
        }
    }
    for (int i : res)
    {
        cout << setw(2) << setfill('0') << player[i].arriveTime / 3600 << ":" << setw(2) << setfill('0') << player[i].arriveTime / 60 % 60 << ":" << setw(2) << setfill('0') << player[i].arriveTime % 60 << " ";
        cout << setw(2) << setfill('0') << player[i].serveTime / 3600 << ":" << setw(2) << setfill('0') << player[i].serveTime / 60 % 60 << ":" << setw(2) << setfill('0') << player[i].serveTime % 60 << " ";
        cout << (player[i].serveTime - player[i].arriveTime + 30) / 60 << endl;
    }
    for (int i = 1; i <= K; i++)
    {
        if (i != 1)
        {
            cout << " ";
        }
        cout << table[i].serveNumber;
    }
    return 0;
}
/*Some test data
2
10:00:00 30 1
12:00:00 30 1
5 1
3

2
18:00:00 180 1
20:00:00 60 1
1 1
1

1
21:00:00 80 1
1 1
1
*/