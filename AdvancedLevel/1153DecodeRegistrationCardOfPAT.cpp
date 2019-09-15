#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
//Use printf instead of cout to avoid TLE!!! :)
struct Card
{
    string ID;
    int score;
};

struct Site
{
    int Nt, Ns;
    Site():Nt(0), Ns(0){}
}site[1000];

int N, M;
vector<Card> card;
unordered_map<int, int> bucket;

bool compare(const Card * c1, const Card * c2)
{
    if (c1->score == c2->score)
    {
        return c1->ID < c2->ID;
    }
    return c1->score > c2->score;
}

bool _compare(const int & index1, const int & index2)
{
    if (bucket[index1] == bucket[index2])
    {
        return index1 < index2;
    }
    return bucket[index1] > bucket[index2];
}

void print(char type)
{
    vector<Card*> res;
    for (int i = 0; i < N; i++)
    {
        if (card[i].ID[0] == type)
        {
            res.push_back(&card[i]);
        }
    }
    if (res.empty())
    {
        printf("NA\n");
    }
    else
    {
        sort(res.begin(), res.end(), compare);
        for (auto & p : res)
        {
            printf("%s %d\n", p->ID.c_str(), p->score);
        }
    }
}

void _print(string & term)
{
    vector<int> order;
    for (int i = 0; i < N; i++)
    {
        if (card[i].ID.substr(4, 6) == term)
        {
            bucket[stoi(card[i].ID.substr(1, 3))]++;
        }
    }
    if (bucket.empty())
    {
        printf("NA\n");
    }
    else
    {
        for (auto i : bucket)
        {
            order.push_back(i.first);
        }
        sort(order.begin(), order.end(), _compare);
        for (auto & i : order)
        {
            printf("%d %d\n", i, bucket[i]);
        }
        bucket.clear();
    }
}

int main()
{
    int type, siteNum, date;
    string term;
    scanf("%d %d", &N, &M);
    card.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> card[i].ID >> card[i].score;
        siteNum = stoi(card[i].ID.substr(1, 3));
        site[siteNum].Nt++;
        site[siteNum].Ns += card[i].score;
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> type >> term;
        cout << "Case " << i << ": " << type << " " << term << endl;
        switch (type)
        {
            case 1: print(term[0]); break;
            case 2:
                siteNum = stoi(term);
                if (site[siteNum].Nt > 0)
                {
                    printf("%d %d\n", site[siteNum].Nt, site[siteNum].Ns);
                }
                else
                {
                    cout << "NA" << endl;
                }
            break;
            case 3: _print(term); break;
        }
    }
    return 0;
}