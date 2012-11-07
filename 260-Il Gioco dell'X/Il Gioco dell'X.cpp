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
#define BLOCK 0
#define OPEN 1
#define DECIDED 1
#define UNDECIDED 0

/*problem id-260
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
    char name;
}node;

node grid[205][205];

int row;
int col;
int win;
int a[]={1,-1,0,0,-1,1};
int b[]={0,0,1,-1,-1,1};

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
    if(c==row-1) win=DECIDED;
    char ch=n->name;
    grid[r][c].state=VISITED;
    for(i=0;i<6;i++)
    {
    	xx=r+a[i];
    	yy=c+b[i];
    	if(IsValid(xx,yy) && grid[xx][yy].state==UNVISITED && grid[xx][yy].name==ch)
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
	int m=0;
	int n;
	int t;
	char c;
	for(i=0;i<201;i++) for(j=0;j<201;j++) {grid[i][j].x=i; grid[i][j].y=j;}
	while(scanf("%d",&row)==1 && row)
	{
	    getchar();
		col=row;
		for(i=0;i<row;i++) for(j=0;j<col;j++) grid[i][j].state=UNVISITED;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				scanf("%c",&c);
				grid[i][j].name=c;
			}
			getchar();
		}
		win=UNDECIDED;
		for(i=0;i<row;i++)
		{
                  if(grid[i][0].state==UNVISITED && grid[i][0].name=='w') DFS(&grid[i][0]);
                  if(win==DECIDED) {printf("%d W\n",++m); break;}
		}
		if(win==UNDECIDED) printf("%d B\n",++m);
	}
	return 0;
}
