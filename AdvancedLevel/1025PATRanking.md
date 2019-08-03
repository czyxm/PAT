# PAT Ranking
Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.
### Input Specification:
Each input file contains one test case. For each case, the first line contains a positive number N (<=100), the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (<=300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.
### Output Specification:
For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:
registration_number final_rank location_number local_rank
The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.
### Sample Input:
```in
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
```
### Sample Output:
```out
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
```
### Solution
Oh hu~
```C++
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
```