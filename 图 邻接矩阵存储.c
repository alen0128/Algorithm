#include <stdio.h>
#include <string.h>
#define MaxNum 50
typedef char VexType[3];      
typedef struct
{
    VexType V[MaxNum];      
    int E[MaxNum][MaxNum];
    int n , e;  
}MGraph;

int Locate(MGraph* m, char vex[]);  
void Creat(MGraph* m);
void Print(MGraph* m);
int main()
{
    MGraph m;

    Creat(&m);
    Print(&m);
    return 0;
}

int Locate(MGraph* m, char vex[])
{
    int i =0;
    for (i=0; i<m->n; ++i)
    {
        if (strcmp(m->V[i],vex) == 0)
        {
            return i;
        }
    }
}

void Creat(MGraph* m)
{
    int i, j;
    char vex1[3], vex2[3];

    printf("ÊäÈëÍ¼µÄ¶¥µãÊýºÍ±ßÊý£º\n");
    scanf("%d%d",&m->n,&m->e);
    for (i=0; i<m->n; ++i)      
    {
        for (j=0; j<m->n; ++j)
        {
            m->E[i][j] = 0;
        }
    }
    for (i=0; i<m->n; ++i)  
    {
        printf("ÊäÈë¶¥µã%dÐÅÏ¢£º",i+1);
        scanf("%s",m->V[i]);    
    }
    for (i=0; i<m->e; ++i)      
    {
        printf("ÊäÈëµÚ%d¸ö±ßµÄ¶¥µã1£º",i+1);
        scanf("%s",vex1);
        getchar();
        printf("ÊäÈëµÚ%d¸ö±ßµÄ¶¥µã2£º",i+1);
        scanf("%s",vex2);
        m->E[Locate(m,vex1)][Locate(m,vex2)] = 1;
    }
}

void Print(MGraph* m)
{
    int i, j;
    for (i=0; i<m->n; ++i)
    {
        for (j=0; j<m->n; ++j)
        {
            if (m->E[i][j] == 1)
            {
                printf("<%s %s>  ",m->V[i],m->V[j]);
            }
        }
    }
    printf("\n");
}