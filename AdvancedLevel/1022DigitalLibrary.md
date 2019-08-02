# Digital Library
A Digital Library contains millions of books, stored according to their titles, authors, key words of their abstracts, publishers, and published years. Each book is assigned an unique 7-digit number as its ID. Given any query from a reader, you are supposed to output the resulting books, sorted in increasing order of their ID's.
### Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<=10^4) which is the total number of books. Then N blocks follow, each contains the information of a book in 6 lines:
Line #1: the 7-digit ID number;
Line #2: the book title -- a string of no more than 80 characters;
Line #3: the author -- a string of no more than 80 characters;
Line #4: the key words -- each word is a string of no more than 10 characters without any white space, and the keywords are separated by exactly one space;
Line #5: the publisher -- a string of no more than 80 characters;
Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].
It is assumed that each book belongs to one author only, and contains no more than 5 key words; there are no more than 1000 distinct key words in total; and there are no more than 1000 distinct publishers.
After the book information, there is a line containing a positive integer M (<=1000) which is the number of user's search queries. Then M lines follow, each in one of the formats shown below:
1: a book title
2: name of an author
3: a key word
4: name of a publisher
5: a 4-digit number representing the year
### Output Specification:
For each query, first print the original query in a line, then output the resulting book ID's in increasing order, each occupying a line. If no book is found, print Not Found instead.
### Sample Input:
```in
3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla
```
### Sample Output:
```out
1: The Testing Book
1111111
2222222
2: Yue Chen
1111111
3333333
3: keywords
1111111
2222222
3333333
4: ZUCS Print
1111111
5: 2011
1111111
2222222
3: blablabla
Not Found
```
### Solution
Just note that the usage of `getline()`, especially in the case that `cin` before `getline()`(use `getchar()` to eliminate the space).

```C+++
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
//Structure node for book
typedef struct BookNode
{
    string ID;
    string title;
    string author;
    set<string> keywords;
    string publisher;
    string year;
}* BNode;
//Compare function of sorting books
bool compare(const BNode & book1, const BNode & book2)
{
    return book1->ID < book2->ID;
}

int main()
{
    string orderStr, queryStr, keywordStr;
    int bookNum, queryNum, flag, found;
    vector<BNode> book, result;
    cin >> bookNum;
    getchar();
    for (int i = 1; i <= bookNum; i++)
    {
        BNode newBook = new BookNode;
        getline(cin, newBook->ID);
        getline(cin, newBook->title);
        getline(cin, newBook->author);
        getline(cin, keywordStr);
        getline(cin, newBook->publisher);
        getline(cin, newBook->year);
        //Parse keywords
        istringstream sin(keywordStr);
        while (sin)
        {
            sin >> queryStr;
            newBook->keywords.insert(queryStr);
        }
        book.push_back(newBook);
    }
    //Sort books by ID
    sort(book.begin(), book.end(), compare);
    cin >> queryNum;
    for (int i = 1; i <= queryNum; i++)
    {
        cin >> orderStr;
        getchar();
        getline(cin, queryStr);
        cout << orderStr << " " << queryStr << endl;
        found = false;
        for (int i = 0; i < book.size(); i++)
        {
            flag = false;
            switch (orderStr[0])
            {
                case '1' : if (book[i]->title == queryStr){ flag = true; } break;
                case '2' : if (book[i]->author == queryStr){ flag = true; } break;
                case '3' : if (book[i]->keywords.find(queryStr) != book[i]->keywords.end()){ flag = true; } break;
                case '4' : if (book[i]->publisher == queryStr){ flag = true; } break;
                case '5' : if (book[i]->year == queryStr){ flag = true; } break;
            }
            if (flag)
            {
                found = true;
                cout << book[i]->ID << endl;
            }
        }
        if (!found)
        {
            cout << "Not Found" << endl;
        } 
    }
    return 0;
}
```