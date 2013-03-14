#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxNum 20

typedef char VexData[3];   

typedef struct ArcNode  
{
    int adjvex;     
    struct ArcNode* nextarc;   
}ArcNode;

typedef struct Vnode 
{
    VexData data;   
    struct Vnode* firstarc;   
}Vnode, AdjList[MaxNum];

typedef struct      
{
    AdjList vertices;   
    int e, n;       
}Graph;

int Locate(Graph* m, VexData vex);
void Creat(Graph* m);

int main()
{
    Graph m;
    Creat(m);
    return 0;
}

int Locate(Graph* m, VexData vex)
{
    int i;
    for (i=0; i<m->e; ++i)
    {
        if (strcmp(m->vertices[i].data,vex) == 0)
        {
            return i;
        }
    }
}
void Creat(Graph* m)
{
    VexData vex1, vex2;
    int i, j, k;

    printf("ÊäÈë¶¥µãÊýºÍ±ßÊý£º");
    scanf("%d%d",&m->e,&m->n);
    for (i=0; i<m->e; ++i)
    {
        scanf("%s",m->vertices[i].data);
    }
}