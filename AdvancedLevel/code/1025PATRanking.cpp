#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//Structure node for testee
typedef struct TesteeNode
{
    int score;
    int localRank;
    int locationNumber;
    int finalRank;
    string registrationNumber;
}*TNode;
//Compare function for sorting testees
bool compare(const TNode & t1, const TNode & t2)
{
    if (t1->score > t2->score || (t1->score == t2->score && t1->registrationNumber < t2->registrationNumber))
    {
        return true;
    }
    return false;
}
//Merge two testee vectors
vector<TNode> merge(const vector<TNode> & v1, const vector<TNode> & v2)
{
    vector<TNode> v;
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (compare(v1[i], v2[j]))
        {
            v.push_back(v1[i++]);
        }
        else
        {
            v.push_back(v2[j++]);
        }
    }
    while (i < v1.size())
    {
        v.push_back(v1[i++]);
    }
    while (j < v2.size())
    {
        v.push_back(v2[j++]);
    }
    return v;
}

int main()
{
    int N, M, location = 1;
    vector<TNode> testee, localTestee;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> M;
        for (int j = 1; j <= M; j++)
        {
            TNode newTestee = new TesteeNode;
            cin >> newTestee->registrationNumber >> newTestee->score;
            newTestee->locationNumber = location;
            localTestee.push_back(newTestee);
        }
        sort(localTestee.begin(), localTestee.end(), compare);
        localTestee.front()->localRank = 1;
        for (int k = 1; k < localTestee.size(); k++)
        {
            if (localTestee[k]->score == localTestee[k - 1]->score)
            {
                localTestee[k]->localRank = localTestee[k - 1]->localRank;
            }
            else
            {
                localTestee[k]->localRank = k + 1;
            }
        }
        testee = merge(testee, localTestee);
        localTestee.clear();
        location++;
    }
    testee.front()->finalRank = 1;
    cout << testee.size() << endl << testee.front()->registrationNumber << " " << testee.front()->finalRank \
    << " " << testee.front()->locationNumber << " " << testee.front()->localRank << endl;
    for (int k = 1; k < testee.size(); k++)
    {
        if (testee[k]->score == testee[k - 1]->score)
        {
            testee[k]->finalRank = testee[k - 1]->finalRank;
        }
        else
        {
            testee[k]->finalRank = k + 1;
        }
        cout << testee[k]->registrationNumber << " " << testee[k]->finalRank \
        << " " << testee[k]->locationNumber << " " << testee[k]->localRank << endl;
    }
    return 0;
}