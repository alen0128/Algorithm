#include <iostream>
#include <cstdio>
using namespace std;
#define M 100000
int d[M];
int n;

int find(int x)
{
    while (d[x] != x)
    {
        int t = d[x];
        x = d[t];
    }
}

int

int main()
{

    return 0;
}
*/



#include <isotream>
using namespace std;
int d[M];
int n;
int m;


int find(int x)
{
    int r = x;

    while(d[r] != r)
        r= d[r];
    return r;
}

void hebing(int x, int y)
{
    d[find(x)] = find(y);
}

bool ques(int x, int y)
{
    return (find(x) == find(y));
}

void init()
{
    if(scanf("%d%d",&n,&m) != EOF) return 0;
    for(int i=0; i<n; ++i) d[i] = i;
    return 1;
}

int main()
{

    return 0;
}
