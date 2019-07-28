# The Best Rank
To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algrbra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.

For example, The grades of C, M, E and A - Average of 4 students are given as the following:
```
StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
```

Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

### Input Specification:
Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (¡Ü2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.

### Output Specification:
For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.

The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.

If a student is not on the grading list, simply output N/A.

### Sample Input:
```in
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
```

### Sample Output:
```out
1 C
1 M
1 E
1 A
3 A
N/A
```

### Solution
Store the grades into a (4 X N) 2-D array --
* Each row is the grades of the same student, with the order: total_score, C, M, E
* Each column is all the grades of the same course
Firstly, count the number of grades higher than each grade, and then assign the corresponding rank. THen find the highest rank in each row as the best rank.
Of course you can sort the grades in each column and try to caculate the rank, howbeit it maybe more complicated, I think :).

```C++
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
```