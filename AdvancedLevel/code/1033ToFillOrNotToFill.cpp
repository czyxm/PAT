#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct StationNode
{
    float distance;
    float price;
}* SNode;

bool compare(const SNode & s1, const SNode & s2)
{
    return s1->distance < s2->distance;
}

int main()
{
    int N;
    float capacity, distance, maxDistance, avgDistance, cost, leftGas;
    vector<SNode> station;
    cin >> capacity >> maxDistance >> avgDistance >> N;
    for (int i = 1; i <= N; i++)
    {
        SNode newStation = new StationNode;
        cin >> newStation->price >> newStation->distance;
        if (newStation->distance < maxDistance)
        {
            station.push_back(newStation);
        }
    }
    sort(station.begin(), station.end(), compare);
    if (maxDistance == 0)
    {
        cout << "0.00";
        return 0;
    }
    if (station.front()->distance > 0)
    {
        cout << "The maximum travel distance = 0.00";
        return 0;
    }
    cost = distance = leftGas = 0;
    int i = 0, nextCheaperStation, cheapestStation;
    while (true)
    {
        nextCheaperStation = -1;
        cheapestStation = -1;
        for (int j = i + 1; j < station.size() && station[j]->distance - distance <= capacity * avgDistance; j++)
        {
            if (cheapestStation == -1 || station[j]->price < station[cheapestStation]->price)
            {
                cheapestStation = j;
            }
            if (station[j]->price < station[i]->price)
            {
                nextCheaperStation = j;
                break;
            }
        }
        if (nextCheaperStation == -1)
        {
            //cout << leftGas << "left," << i << "+" << (capacity - leftGas) << endl;
            if (distance + capacity * avgDistance >= maxDistance)
            {
                cost += (maxDistance - distance) / avgDistance * station[i]->price;
                cout << setprecision(2) << fixed << cost;
                break;
            }
            if (cheapestStation == - 1)
            {
                distance += capacity * avgDistance;
                cout << "The maximum travel distance = " << setprecision(2) << fixed << distance;
                break;
            }
            cost += (capacity - leftGas) * station[i]->price;
            leftGas = capacity - (station[cheapestStation]->distance - distance) / avgDistance;
            i = cheapestStation;
        }
        else
        {
            if (leftGas * avgDistance < station[nextCheaperStation]->distance - distance)
            {
                //cout << leftGas << "left," << i << "+" << (station[nextCheaperStation]->distance - distance) / avgDistance - leftGas << endl;
                cost += ((station[nextCheaperStation]->distance - distance) / avgDistance - leftGas) * station[i]->price;
                leftGas = 0;
            }
            else
            {
                //cout << leftGas << "left," << i << "+0" << endl;
                leftGas -= (station[nextCheaperStation]->distance - distance) / avgDistance;
            }
            i = nextCheaperStation;
        }
        distance = station[i]->distance;
    }
    return 0;
}