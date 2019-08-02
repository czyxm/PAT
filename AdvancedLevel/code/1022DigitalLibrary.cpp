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