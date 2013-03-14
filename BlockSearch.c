#include <stdio.h>
#define ROW 3
#define COL 2
#define LEN 10
typedef struct
{
	int indexkey;   
	int blockpos;   
}INDEX;
int BlockSearch(int searchlist[], INDEX ilist[], int key);
int main()
{
    int searchlist[LEN], i, flag, key; 
    INDEX ilist[ROW][COL] = £û£ý;  

    for (i=0; i<LEN; ++i)
    {
    	scanf("%d",&searchlist[i]);
    }
    printf("Key :");
    scanf("%d",&key);

    flag = BlockSearch(searchlist,ilist,key);
    if (flag != -1)
    {
    	printf("%d\n",flag);
    }
    else
    {
    	printf("no find!\n");
    }
    return 0;
}

int BlockSearch(int searchlist[], INDEX ilist[], int key)
{
    int low=0, high=LEN-1, pos=0;

    while (ilist[pos][0]<key && pos<ROW)    
    {
    	++pos;
    }

    if (ilist[pos][0] < key)    
    {
        return -1;
    }

    if (pos == ROW-1)    
    {
        low = ilist[ROW-1][1];
        high = LEN -1;
    }
    else       
    {
        low = ilist[pos][1];
        high = ilist[++pos][1] - 1;
    }

    pos = low;
    while (pos <= high)
    {
    	if (searchlist[pos] == key)
    	{
    		return pos;
    	}
    	else
    	{
    		++pos;
    	}
    }
    return -1; 
}
