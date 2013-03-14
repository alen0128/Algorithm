#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxNum 10
int sign[MaxNum];   
int graph[MaxNum][MaxNum]={{0,1,1,0},{0,0,1,1},{1,1,0,0},{0,1,1,0}};
int len, i;
void DFS(int i);
int main()
{
    memset(sign,0,sizeof(sign));
    printf("len: ");
    scanf("%d",&len);
    DFS(0);
    return 0;
}

void DFS(int i)
{
    int j;
    printf("%d",i+1);
    sign[i] = 1;
    for (j=0; j<len; ++j)
    {
        if (sign[j]==0 && graph[i][j]==1)
        {
            printf("->");
            DFS(j);
        }
    }
}
