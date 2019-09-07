#include<bits/stdc++.h>
using namespace std;

struct Graph
{
    int Nv, Ne;
    unordered_map<int, bool> relationList;
    vector<int> sameSexFriend[10000];
}graph;

struct Pair
{
    int first, second;
    Pair(int first, int second):first(first), second(second){}
    bool operator<(const Pair & p)const
    {
        if (first == p.first)
        {
            return second < p.second;
        }
        return first < p.first;
    }
};

int source, target;
vector<Pair> friends;

int main()
{
    string str1, str2;  //Read input IDs by string instead of int => -0000
    int ID1, ID2, K;
    cin >> graph.Nv >> graph.Ne;
    for (int i = 1; i <= graph.Ne; i++)
    {
        cin >> str1 >> str2;
        ID1 = str1[0] == '-' ? stoi(str1.substr(1)) : stoi(str1);
        ID2 = str2[0] == '-' ? stoi(str2.substr(1)) : stoi(str2);
        graph.relationList.insert(pair<int, bool>(ID1 * 10000 + ID2, true));
        graph.relationList.insert(pair<int, bool>(ID2 * 10000 + ID1, true));
        if (str1.size() == str2.size())
        {
            graph.sameSexFriend[ID1].push_back(ID2);
            graph.sameSexFriend[ID2].push_back(ID1);
        }
    }
    cin >> K;
    for (int i = 1; i <= K; i++)
    {
        cin >> source >> target;
        source = abs(source);
        target = abs(target);
        friends.clear();
        for (int i = 0; i < graph.sameSexFriend[source].size(); i++)
        {
            ID1 = graph.sameSexFriend[source][i];
            for (int j = 0; j < graph.sameSexFriend[target].size(); j++)
            {
                ID2 = graph.sameSexFriend[target][j];
                if (ID1 != target && ID2 != source && graph.relationList[ID1 * 10000 + ID2] == true)
                {
                    friends.push_back(Pair(ID1, ID2));
                }
            }
        }
        sort(friends.begin(), friends.end());
        cout << friends.size() << endl;
        auto begin = friends.begin(), end = friends.end();
        while (begin != end)
        {
            cout << setw(4) << setfill('0') << begin->first << " " << setw(4) << setfill('0') << begin->second << endl;
            begin++;
        }
    }
    return 0;
}
/*DFS => TLE
#include<bits/stdc++.h>
using namespace std;

struct Graph
{
    int Nv, Ne;
    vector<int> relationList[10000];
    vector<int> sameSexFriend[10000];
    bool gender[10000], known[10000] = {false};
}graph;

struct Pair
{
    int first, second;
    Pair(int first, int second):first(first), second(second){}
    bool operator<(const Pair & p)const
    {
        if (first == p.first)
        {
            return second < p.second;
        }
        return first < p.first;
    }
};

int source, target;
vector<Pair> friends;
vector<int> path;

void DFS(int people)
{
    path.push_back(people);
    graph.known[people] = true;
    if (path.size() == 4)
    {
        if (people == target)
        {
            friends.push_back(Pair(path[1], path[2]));
        }
    }
    else if (path.size() < 4)
    {
        bool nextGender = path.size() < 2 ? graph.gender[source] : graph.gender[target];
        int _friend;
        for (int i = 0; i < graph.relationList[people].size(); i++)
        {
            _friend = graph.relationList[people][i];
            if (graph.gender[_friend] == nextGender && !graph.known[_friend])
            {
                DFS(_friend);
            }
        }
    }
    graph.known[people] = false;
    path.pop_back();
}

int main()
{
    string str1, str2;  //Read input IDs by string instead of int => -0000
    int ID1, ID2;
    cin >> graph.Nv >> graph.Ne;
    for (int i = 1; i <= graph.Ne; i++)
    {
        cin >> str1 >> str2;
        if (str1[0] == '-')
        {
            ID1 = stoi(str1.substr(1));
            graph.gender[ID1] = false;
        }
        else
        {
            ID1 = stoi(str1);
            graph.gender[ID1] = true;
        }
        if (str2[0] == '-')
        {
            ID2 = stoi(str2.substr(1));
            graph.gender[ID2] = false;
        }
        else
        {
            ID2 = stoi(str2);
            graph.gender[ID2] = true;
        }
        graph.relationList[ID1].push_back(ID2);
        graph.relationList[ID2].push_back(ID1);
    }
    int K;
    cin >> K;
    for (int i = 1; i <= K; i++)
    {
        cin >> source >> target;
        source = abs(source);
        target = abs(target);
        friends.clear();
        DFS(source);
        sort(friends.begin(), friends.end());
        cout << friends.size() << endl;
        auto begin = friends.begin(), end = friends.end();
        while (begin != end)
        {
            cout << setw(4) << setfill('0') << begin->first << " " << setw(4) << setfill('0') << begin->second << endl;
            begin++;
        }
    }
    return 0;
}
*/