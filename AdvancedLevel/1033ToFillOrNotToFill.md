# To Fill or Not to Fill
With highways available, driving a car from Hangzhou to any other city is easy. But since the tank capacity of a car is limited, we have to find gas stations on the way from time to time. Different gas station may give different price. You are asked to carefully design the cheapest route to go.
### Input Specification:
Each input file contains one test case. For each case, the first line contains 4 positive numbers: Cmax(<=> 100), the maximum capacity of the tank; D (<=30000), the distance between Hangzhou and the destination city; D_avg(<=20), the average distance per unit gas that the car can run; and N (<=500), the total number of gas stations. Then N lines follow, each contains a pair of non-negative numbers: Pi, the unit gas price, and Di(<=D), the distance between this station and Hangzhou, for i=1,...,N. All the numbers in a line are separated by a space.
### Output Specification:
For each test case, print the cheapest price in a line, accurate up to 2 decimal places. It is assumed that the tank is empty at the beginning. If it is impossible to reach the destination, print The maximum travel distance = X where X is the maximum possible distance the car can run, accurate up to 2 decimal places.
### Sample Input 1:
```in
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
```
### Sample Output 1:
```out
749.17
```
### Sample Input 2:
```in
50 1300 12 2
7.10 0
7.00 600
```
### Sample Output 2:
```out
The maximum travel distance = 1200.00
```
### Solution
Greedy algorithm: Sort all the station by their distance first, for current position we can find the stations that it can reach to:
* if there's a station with cheaper price then go to there.
* if no cheaper station
  * if the terminal station is within reach then go to the terminal station directly.
  * if not, find the cheapest station amoung them, then fill up the car with gas to go there.
  * if not, it must impossible to reach the terminal station, just caculate the distance and print it.

Special case:
* If the nearest station's distance is bigger than 0, then the car cannot depart, distance = "0.00"
* If the terminal station is the start station, then the cost = "0.00"

Finally, take care of the output format. Good luck!
  
```C++
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
```