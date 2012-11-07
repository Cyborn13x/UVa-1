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
#define N 105

/*problem id-11244
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
}node;

node grid[N][N];

int counter;
int row;
int col;
int a[]={0,0,1,-1,1,1,-1,-1};
int b[]={1,-1,0,0,1,-1,1,-1};

bool IsValid(int r,int c)
{
    if(r>=0 && r<row && c>=0 && c<col) return 1;
    return 0;
}

void DFS(node *n)
{
    int i;
    int r=n->x;
    int c=n->y;
    int xx;
    int yy;
    counter++;
    grid[r][c].state=VISITED;
    for(i=0;i<8;i++)
    {
    	xx=r+a[i];
    	yy=c+b[i];
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
	int ans;
	char c;
	for(i=0;i<N;i++) for(j=0;j<N;j++) {grid[i][j].x=i; grid[i][j].y=j;}
	while(scanf("%d %d\n",&row,&col)==2 && row && col)
	{
	    ans=0;
		for(i=0;i<row;i++) for(j=0;j<col;j++) grid[i][j].state=UNVISITED;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
                scanf("%c",&c);
				if(c=='.') grid[i][j].state = VISITED;
			}
			getchar();
		}
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				if(grid[i][j].state==UNVISITED)
				{
				    counter=0;
				    DFS(&grid[i][j]);
				    if(counter==1) ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
