#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctime>
using namespace std;

const int MaxNum = 5;
int Search(int num[], int len, int value);
int main()
{
    //srand(time(NULL));
    int num[MaxNum];

    for (int i=0; i<MaxNum; ++i)
    {
        //num[i] = rand() % 100;
        cin >> num[i];
    }
    sort(num,num+MaxNum);
    cout << Search(num,MaxNum,0) << endl;
}

int Search(int num[], int len, int value)
{
    int mid, low=0, high=len-1;

    while (low <= high)
    {
        mid = (low + high) >> 1;    //
        if (num[mid] == value)
            return mid;
        if (num[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
