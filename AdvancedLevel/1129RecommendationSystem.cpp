//STL - set is implemented with Red-Black tree
#include<bits/stdc++.h>
using namespace std;

class Item
{
public:
    int key;
    int frequency;
    Item(int key, int frequency):key(key), frequency(frequency){}
    bool operator< (const Item & item) const
    {
        if (frequency == item.frequency)
        {
            return key < item.key;
        }
        return frequency > item.frequency;
    }
};

int main()
{
    int N, K;
    cin >> N >> K;
    set<Item> rec;
    vector<int> frequency(50001, 0);
    Item item1(0, 1);
    cin >> item1.key;
    rec.insert(item1);
    frequency[item1.key] = 1;
    for (int i = 2; i <= N; i++)
    {
        Item item2(0, 1);
        cin >> item2.key;
        cout << item2.key << ":";
        int size = min(K, (int)rec.size());
        auto begin = rec.begin();
        while (size > 0)
        {
            cout << " " << begin->key;
            begin++;
            size--;
        }
        cout << endl;
        auto iter = rec.find(Item(item2.key, frequency[item2.key]));
        if (iter != rec.end())
        {
            rec.erase(iter);
            item2.frequency = ++frequency[item2.key];
        }
        else
        {
            frequency[item2.key] = 1;
        }
        rec.insert(item2);
    }
    return 0;
}
/*Insert sort => TLE
#include<bits/stdc++.h>
using namespace std;

int frequency[50001] = {0}, position[50001] = {-1};

bool compare(const int & r1, const int & r2)
{
    if (frequency[r1] == frequency[r2])
    {
        return r1 < r2;
    }
    return frequency[r1] > frequency[r2];
}

int main()
{
    int N, K, item;
    cin >> N >> K;
    vector<int> rec;
    cin >> item;
    frequency[item]++;
    rec.push_back(item);
    position[item] = 0;
    for (int i = 2; i <= N; i++)
    {
        cin >> item;
        cout << item << ":";
        for (int j = 0; j < K && j < rec.size(); j++)
        {
            cout << " " << rec[j];
        }
        cout << endl;
        if (frequency[item] == 0)
        {
            position[item] = rec.size();
            rec.push_back(item);
        }
        frequency[item]++;
        int pos = position[item] - 1;
        while (pos >= 0 && compare(item, rec[pos]))
        {
            rec[pos + 1] = rec[pos];
            position[rec[pos]]++;
            pos--;
        }
        rec[pos + 1] = item;
        position[item] = pos + 1;
    }
    return 0;
}
*/