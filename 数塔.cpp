#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int num[105][105], icase, row;

    cin >> icase;
    while (icase--)
    {
    	cin >> row;
    	for (int i=1; i<=row; ++i)
    	{
    		for (int j=1; j<=i; ++j)
    		{
                cin >> num[i][j];
    		}
    	}

        for (int i=row-1; i>=1; --i)
        {
        	for (int j=1; j<=i; ++j)
        	{
                num[i][j] += (num[i+1][j] > num[i+1][j+1] ? num[i+1][j] : num[i+1][j+1]);
        	}
        }
        cout << num[1][1] << endl;
    }
    return 0;
}
