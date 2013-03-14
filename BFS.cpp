#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

#define MaxNum 10
int graph[MaxNum][MaxNum]={{0,1,1,1},{0,0,1,1},{1,1,0,0},{1,1,1,0}};
int sign[MaxNum], d[MaxNum], len;
queue <int> Q;
void BFS(int k);

int main()
{
    memset(sign,0,sizeof(sign));
    memset(d,0,sizeof(d));

    cin >> len;
    BFS(0);

    for (int i=0; i<len; ++i)
        cout << d[i] << "\n";

    return 0;
}

void BFS(int k)
{
    int i, j;

    //cout << k+1;
    sign[k] = 1;       
    d[k] = 0;
    Q.push(k);

    while (!Q.empty())
    {
        i = Q.front();
        Q.pop();
        for (j=0; j<len; ++j)    
        {
            if (graph[i][j]==1 && sign[j]==0)
            {
                //cout << "->" << j+1;
                sign[j] = 1;
                d[j] = d[i] + 1;       
                Q.push(j);             
            }
        }
    }
}
