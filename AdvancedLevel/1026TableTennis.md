# Table Tennis
A table tennis club has N tables available to the public. The tables are numbered from 1 to N. For any pair of players, if there are some tables open when they arrive, they will be assigned to the available table with the smallest number. If all the tables are occupied, they will have to wait in a queue. It is assumed that every pair of players can play for at most 2 hours.
Your job is to count for everyone in queue their waiting time, and for each table the number of players it has served for the day.
One thing that makes this procedure a bit complicated is that the club reserves some tables for their VIP members. When a VIP table is open, the first VIP pair in the queue will have the priviledge to take it. However, if there is no VIP in the queue, the next pair of players can take it. On the other hand, if when it is the turn of a VIP pair, yet no VIP table is available, they can be assigned as any ordinary players.
### Input Specification:
Each input file contains one test case. For each case, the first line contains an integer N (<=10000) - the total number of pairs of players. Then N lines follow, each contains 2 times and a VIP tag: HH:MM:SS - the arriving time, P - the playing time in minutes of a pair of players, and tag - which is 1 if they hold a VIP card, or 0 if not. It is guaranteed that the arriving time is between 08:00:00 and 21:00:00 while the club is open. It is assumed that no two customers arrives at the same time. Following the players' info, there are 2 positive integers: K (<=100) - the number of tables, and M (< K) - the number of VIP tables. The last line contains M table numbers.
### Output Specification:
For each test case, first print the arriving time, serving time and the waiting time for each pair of players in the format shown by the sample. Then print in a line the number of players served by each table. Notice that the output must be listed in chronological order of the serving time. The waiting time must be rounded up to an integer minute(s). If one cannot get a table before the closing time, their information must NOT be printed.
### Sample Input:
```in
9
20:52:00 10 0
08:00:00 20 0
08:02:00 30 0
20:51:00 10 0
08:10:00 5 0
08:12:00 10 1
20:50:00 10 0
08:01:30 15 1
20:53:00 10 1
3 1
2
```
### Sample Output:
```out
08:00:00 08:00:00 0
08:01:30 08:01:30 0
08:02:00 08:02:00 0
08:12:00 08:16:30 5
08:10:00 08:20:00 10
20:50:00 20:50:00 0
20:51:00 20:51:00 0
20:52:00 20:52:00 0
3 3 2
```
### Solution
29...A segment error at the last test point. S**t!
```C++
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//Structure node for player
typedef struct PlayerNode
{
    int arriveTime;
    int serveTime;
    int waitTime;
    int playTime;
    int isVIP;
}* PNode;
//Structure node for table
typedef struct TableNode
{
    int serveNumber;
    int spareTime;
    int isVIP;
}* TNode;
//Compare function for sorting players by arrive time
bool compare(const PNode & p1, const PNode & p2)
{
    return p1->arriveTime < p2->arriveTime;
}

int main()
{
    int N, K, M, tableIndex, vipTableIndex, playerIndex;
    string timeStr;
    vector<PNode> player;
    vector<TNode> table;
    vector<PNode> servedPlayer;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        PNode newPlayer = new PlayerNode;
        cin >> timeStr >> newPlayer->playTime >> newPlayer->isVIP;
        //Play time must be at most 2 hours
        if (newPlayer->playTime > 120)
        {
            newPlayer->playTime = 120;
        }
        newPlayer->playTime *= 60;  //Transfer to seconds
        newPlayer->arriveTime = stoi(timeStr.substr(0, 2)) * 3600 + stoi(timeStr.substr(3, 2)) * 60 + stoi(timeStr.substr(6, 2));
        player.push_back(newPlayer);
    }
    sort(player.begin(), player.end(), compare);
    cin >> K >> M;
    for (int i = 0; i < K; i++)
    {
        TNode newTable = new TableNode;
        newTable->serveNumber = newTable->spareTime = newTable->isVIP = 0;
        table.push_back(newTable);
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> tableIndex;
        table[tableIndex - 1]->isVIP = 1;
    }

    for (int i = 0; i < player.size(); i++)
    {
        if (player[i] == nullptr) 
        {
            continue;
        }
        //Find the index of the table that finish its current service earliset 
        tableIndex = 0; 
        for (int j = 1; j < K; j++)
        {
            if (table[j]->spareTime < table[tableIndex]->spareTime)
            {
                tableIndex = j;
            }
        }
        //If the next player comes later than the table's spare time
        if (player[i]->arriveTime >= table[tableIndex]->spareTime)
        {
            if (player[i]->arriveTime >= 21 * 3600)
            {
                break;
            }
            if (player[i]->isVIP == 1)
            {
                vipTableIndex = -1;
                for (int j = 0; j < K; j++)
                {
                    if (table[j]->isVIP == 1 && player[i]->arriveTime >= table[j]->spareTime)
                    {
                        if (vipTableIndex == -1 || table[j]->spareTime < table[vipTableIndex]->spareTime)
                            vipTableIndex = j;
                    }
                }
                if (vipTableIndex != -1)
                {
                    tableIndex = vipTableIndex;
                }
            }
            player[i]->waitTime = 0;
            table[tableIndex]->spareTime = player[i]->arriveTime + player[i]->playTime;
            servedPlayer.push_back(player[i]);
            table[tableIndex]->serveNumber++;
        }
        //If the next player comes earlier than the table's spare time
        else
        {
            if (table[tableIndex]->spareTime >= 21 * 3600)
            {
                break;
            }
            playerIndex = i;
            if (table[tableIndex]->isVIP == 1)
            {
                for (int j = i; j < player.size() && player[j]->arriveTime <= table[tableIndex]->spareTime; j++)
                {
                    if (player[j]->isVIP == 1)
                    {
                        playerIndex = j;
                        break;
                    }
                }
            }
            player[playerIndex]->waitTime = table[tableIndex]->spareTime - player[playerIndex]->arriveTime;
            servedPlayer.push_back(player[playerIndex]); 
            table[tableIndex]->spareTime += player[playerIndex]->playTime;
            table[tableIndex]->serveNumber++;
            if (playerIndex != i)
            {
                player[playerIndex] = nullptr;
                i--;
            }
        }
    }
    for (int i = 0; i < servedPlayer.size(); i++)
    {
        servedPlayer[i]->serveTime = servedPlayer[i]->arriveTime + servedPlayer[i]->waitTime;
        cout << setfill('0') << setw(2) << servedPlayer[i]->arriveTime / 3600 << ":" << setfill('0') << setw(2) << servedPlayer[i]->arriveTime / 60 % 60 << ":" << setfill('0') << setw(2) << servedPlayer[i]->arriveTime % 60 << " ";
        cout << setfill('0') << setw(2) << servedPlayer[i]->serveTime / 3600 << ":" << setfill('0') << setw(2) << servedPlayer[i]->serveTime / 60 % 60 << ":" << setfill('0') << setw(2) << servedPlayer[i]->serveTime % 60 << " ";
        cout << (servedPlayer[i]->waitTime + 30) / 60 << endl;
    }
    for (int i = 0; i < table.size(); i++)
    {
        cout << table[i]->serveNumber;
        if (i < table.size() - 1)
        {
            cout << " ";
        }
    }
    return 0;
}
```