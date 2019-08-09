#include<iostream>
#define MAX(x,y) (x)>(y)?(x):(y)
void FindPeak(int n, int *A);
using namespace std;
int main()
{
    int n, *A;
    cin >> n;
    A = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    FindPeak(n, A);
}
void FindPeak(int n, int *A) 
{
	int index = 0, i, j; //The index of the peak element in the result
	int *up = new int[n + 1], *down = new int[n + 1];  //Maximun length of ascending sequence and descending sequence
	//Initialize the two arrays
	for (int i = 0; i <= n; i++)
	{
		up[i] = down[i] = 0;
	}
	//Caculate the length of maximum ascending sequence
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (A[i] > A[j])
				up[i] = MAX(up[i], up[j] + 1);
		}	
	}
	//Caculate the length of maximum descending sequence
	for (int i = n; i >= 1; i--)
	{
		for (int j = n; j > i; j--)
		{
			if (A[i] > A[j])
				down[i] = MAX(down[i], down[j] + 1);
		}
	}		
	//Find a peak with maximum length
	for (int i = 1; i <= n; ++i)
	{
		if (up[i] && down[i])
		{
			//Longer length or the same length but more symmetric
			if (up[i] + down[i] > up[index] + down[index] ||
			   (up[i] + down[i] == up[index] + down[index] && abs(up[i] - down[i]) < abs(up[index] - down[index])))
			{
				index = i;
			}
		}
	}
	//Display the result		
	if (index == 0)  //Not found a peak
		cout << "No peak shape";
	else             //format: length index value
	    cout << up[index] + down[index] + 1 << " " << index << " " << A[index];
}