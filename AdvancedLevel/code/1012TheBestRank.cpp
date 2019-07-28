#include<iostream>
#include<string>
#include<map>
using namespace std;

//Find the index of the minmum element int the array
int minIdx(int * data, int n)
{
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        index = data[i] < data[index] ? i : index;
    }
    return index;
}

int main()
{
    int N, M, maxScoreIndex;
    string testStuID;
    char course[4] = {'A', 'C', 'M', 'E'};
    map<string, int> stuID;  //Map the student ID string to the index from 0 to N - 1
    int **grade, **rank;     //2-D array of grades and ranks, whose first column is the total score and its rank
    cin >> N >> M;
    grade = new int* [N];
    rank = new int* [N];
    for (int i = 0; i < N; i++)
    {
        //Initial rank
        rank[i] = new int [4];
        rank[i][0] = rank[i][1] = rank[i][2] = rank[i][3] = 1;
        //Read grades and caculate the total score
        grade[i] = new int [4];
        cin >> testStuID >> grade[i][1] >> grade[i][2] >> grade[i][3];
        grade[i][0] = grade[i][1] + grade[i][2] + grade[i][3];
        //Insert ID-index pair
        stuID.insert(pair<string, int>(testStuID, i)); 
    }

    //Rank
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < N; i++)
        {
            //Count the number of elements that bigger than current grade
            for (int k = 0; k < N; k++)
            {
                if (grade[k][j] > grade[i][j])
                {
                    rank[i][j]++;
                }
            }
        }
    }

    for (int i = 1; i <= M; i++)
    {
        //Read the test ID
        cin >> testStuID;
        //Find test ID in the map
        map<string, int>::iterator iter = stuID.find(testStuID);
        if (iter == stuID.end())
        {
            cout << "N/A" << endl;  //Not such a ID
        } 
        else
        {
            //Find the highest rank
            int index = minIdx(rank[iter->second], 4);
            cout << rank[iter->second][index] << " " << course[index] << endl;
        }
    }

    delete [] rank;
    delete [] grade;
    return 0;
}