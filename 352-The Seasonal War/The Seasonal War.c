#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define VISITED 1
#define UNVISITED 0
#define BLOCK 0
#define OPEN 1

/*problem id-352
 *
 *language-ANSI C
 *
 */

typedef struct
{
    int x;
    int y;
    int color;
    int state;
}node;

node Grid[26][26];


int m;
int n;
int ans;
int a[]={0,1,1,1,0,-1,-1,-1};
int b[]={1,1,0,-1,-1,-1,0,1};

int IsValid(int xx,int yy)
{
    if(xx>=0 && xx<m && yy>=0 && yy<n) return 1;
    return 0;
}

void DFS(node *n)
{
    int r=n->x;
    int c=n->y;
    int xx;
    int yy;
    int i;
    int j;
    n->color = VISITED;
    for(i=0;i<8;i++)
    {
    	xx=r+a[i];
    	yy=c+b[i];
    	if(IsValid(xx,yy) && Grid[xx][yy].state==OPEN && Grid[xx][yy].color==UNVISITED)
    	{
    	    DFS(&Grid[xx][yy]);
    	}
    }
    return;
}

int main()
{
	int i;
	int j;
	int k=0;
	int l;
	int t;
	char c[30];
	while(scanf("%d\n",&m)!=EOF)
	{
	    n=m;
	    ans=0;
	    for(i=0;i<m;i++)
	    {
	    	for(j=0;j<n;j++)
	    	{
	    		Grid[i][j].x=i;
	    		Grid[i][j].y=j;
	    		Grid[i][j].color=UNVISITED;
	    	}
	    }
		for(i=0;i<m;i++)
		{
            scanf("%s",c);
            for(t=0;t<m;t++)
            {
                Grid[i][t].state = (c[t]=='0') ? BLOCK : OPEN;
            }
		    getchar();
		}
		for(i=0;i<m;i++)
		{
		    for(j=0;j<n;j++)
		    {
                if(Grid[i][j].state==OPEN && Grid[i][j].color==UNVISITED)
                {
                    ans++;
                    DFS(&Grid[i][j]);
                }
		    }
		}
		printf("Image number %d contains %d war eagles.\n",++k,ans);
	}
	return 0;
}
