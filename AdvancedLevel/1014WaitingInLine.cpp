#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;

int main()
{
    queue<int> * window;
    int N, M, K, Q, customer, index, *processingTime, *finishTime;
    cin >> N >> M >> K >> Q;
    processingTime = new int [K];  //Processing time for customers: minutes
    finishTime = new int [K];      //Finish time: minutes
    window = new queue<int> [N];   //Estimate the windows by queues
    for (int i = 0; i < K; i++)
    {
        cin >> processingTime[i];
        if (i < M * N)
        {
            if (i < N)
            {
                finishTime[i] = processingTime[i];
            }
            else
            {
                finishTime[i] = finishTime[window[i % N].back()] + processingTime[i];
            }
            window[i % N].push(i);
        }
        else
        {
            //Find the index of the earlist window that dequeue a customer
            index = 0;
            for (int j = 1; j < N; j++)
            {
                if (finishTime[window[j].front()] < finishTime[window[index].front()])
                {
                    index = j;
                }
            }
            //Push the next customer into this window
            finishTime[i] = finishTime[window[index].back()] + processingTime[i];
            window[index].pop();
            window[index].push(i);
        }
    }
    for (int i = 1; i <= Q; i++)
    {
        cin >> customer;
        customer--;
        if (finishTime[customer] - processingTime[customer] >= 540)
        {
            cout << "Sorry" << endl;
        }
        else
        {
            finishTime[customer] += 480;
            cout << setfill('0') << setw(2) << finishTime[customer] / 60 << ":" << setfill('0') << setw(2) << finishTime[customer] % 60 << endl;
        }
    }
    delete [] processingTime;
    delete [] finishTime;
    delete [] window;
    return 0;
}