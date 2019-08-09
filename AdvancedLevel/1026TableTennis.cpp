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