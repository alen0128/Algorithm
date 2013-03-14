#include <iostream>
using namespace std;
#define N 200
#define inf 1000000000
int g[N][N]= {{2,1,1,2},{2,2,1,1},{1,1,2,2},{2,1,1,2}};
int dijkstra(int v, int n);
int main()
{
    cout << dijkstra(0,4) << endl;
    return 0;
}

int dijkstra(int v, int n)
{
	int min, minid, i, j;
	int dis[N], mark[N];

	for (i = 1; i <= n; i++)
	{
		dis[i] = g[v][i];
		mark[i] = 0;
	}
	mark[v] = 1;

	for (i = 1; i < n; i++)
	{
		min = inf;
		minid = 0;

		for (j = 1; j <= n; j++)
		{
			if (!mark[j] && dis[j] < min)
			{
				min = dis[j];
				minid = j;
			}
		}

		if (!minid)
			break;
		mark[minid] = 1;
		for (j = 1; j <= n; j++)
		{
			if (!mark[j] && min + g[minid][j] < dis[j])
				dis[j] = min + g[minid][j];
		}
	}
	return min;
}

