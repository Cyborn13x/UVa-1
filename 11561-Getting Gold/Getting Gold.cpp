#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

#define UNVISITED 0
#define VISITED 1

/*problem id-11561
 *
 *language-C++
 *
 */

using namespace std;

typedef struct
{
    int x;
    int y;
    int state;
    int gold;
}node;

node grid[55][55];

int counter;
int row;
int col;
int a[]={0,0,1,-1};
int b[]={1,-1,0,0};

bool IsValid(int r,int c)
{
    if(r>0 && r<row-1 && c>0 && c<col-1) return 1;
    return 0;
}

void DFS(node *n)
{
    int i;
    int r=n->x;
    int c=n->y;
    int xx;
    int yy;
    grid[r][c].state=VISITED;
    for(i=0;i<4;i++)
    {
    	xx=r+a[i];
    	yy=c+b[i];
    	if(grid[xx][yy].gold) {counter++;grid[xx][yy].gold=0;}
    	if(IsValid(xx,yy) && grid[xx][yy].state==UNVISITED)
    	{
    	    DFS(&grid[xx][yy]);
    	}
    }
    return;
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	char c;
	for(i=0;i<55;i++) for(j=0;j<55;j++) {grid[i][j].x=i; grid[i][j].y=j;}
	while(scanf("%d %d\n",&col,&row)!=EOF)
	{
	    counter=0;
		for(i=0;i<row;i++) for(j=0;j<col;j++) {grid[i][j].state=UNVISITED;grid[i][j].gold=0;}
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
                scanf("%c",&c);
				if(c=='P') {m=i;n=j;}
				else if(c=='T')
				{
				    grid[i][j].state = VISITED;
				    for(k=0;k<4;k++)
				    {
				    	l=i+a[k];
				    	t=j+b[k];
				    	grid[l][t].state = VISITED;
				    }
				}
				else if(c=='#') grid[i][j].state = VISITED;
				else if(c=='G') grid[i][j].gold = 1;
			}
			getchar();
		}
		if(grid[m][n].state==UNVISITED) DFS(&grid[m][n]);
		printf("%d\n",counter);
	}
	return 0;
}
