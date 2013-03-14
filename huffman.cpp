#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cfloat>
using namespace std;
const int n = 7;
const int m = 2*n-1;
typedef struct
{
    float weight;
    int lchild, rchild, parent;
}HUFMTREE;
HUFMTREE htree[m];
void Hufmtree();
int main()
{

    return 0;
}

void Hufmtree()
{
    int i, j, p1, p2;      
    double small1, small2; 

    for (i=0; i<m; ++i)     
    {
        htree[i].lchild = htree[i].parent = htree[i].rchild = 0;
        htree[i].weight = 0.0;
    }
    for (i=0; i<n; ++i)     
    {
        scanf("%f",&htree[i].weight);
    }
    for (i=n; i<m; ++i)     
    {
        p1 = p2 = 0;
        small1 = small2 = FLT_MAX;
        for (j=0; j<=i-1; ++j)
        {
            if (htree[j].parent == 0)
            {
                if (htree[j].weight < small1)     
                {
                    small2 = small1;
                    small1 = htree[j].weight;
                    p2 = p1;
                    p1 = j;
                }
                else
                {
                    if (htree[j].weight < small2)      
                    {
                        small2 = htree[j].weight;
                        p2 = j;
                    }
                }
            }
        }

        htree[p1].parent = i;
        htree[p2].parent = i;
        htree[i].lchild = p1;
        htree[i].rchild = p2;
        htree[i].weight = htree[p1].weight + htree[p2].weight;
    }
}
