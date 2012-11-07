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

/*problem id-469
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

node grid[100][100];

int row;
int col;
int val;
int ans;
int a[]={1,-1,0,0,1,1,-1,-1};
int b[]={0,0,1,-1,1,-1,1,-1};

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
    char ch=n->name;
    ans++;
    grid[r][c].state=VISITED;
    for(i=0;i<8;i++)
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

void vis(node *n)
{
    int i;
    int r=n->x;
    int c=n->y;
    int xx;
    int yy;
    char ch=n->name;
    grid[r][c].state=UNVISITED;
    for(i=0;i<8;i++)
    {
    	xx=r+a[i];
    	yy=c+b[i];
    	if(IsValid(xx,yy) && grid[xx][yy].state==VISITED && grid[xx][yy].name==ch)
    	{
    	    vis(&grid[xx][yy]);
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
	bool fl=0;
	char s[105];
	char c;
	for(i=0;i<100;i++) for(j=0;j<100;j++) {grid[i][j].x=i; grid[i][j].y=j;}
	scanf("%d",&t);
	getchar();
	getchar();
	for(k=0;k<t;k++)
	{
	    if(fl) printf("\n");
	    fl=1;
		row=0;
		while(gets(s) && s[0]!='\0')
		{
			l=strlen(s);
			if(s[0]=='W' || s[0]=='L')
			{
			    col=l;
			    for(i=0;i<l;i++)
			    {
			    	grid[row][i].name=s[i];
			    	grid[row][i].state=UNVISITED;
			    }
			    row++;
			}
			else
			{
			    sscanf(s,"%d %d",&m,&n);
			    ans=0;
                DFS(&grid[m-1][n-1]);
                vis(&grid[m-1][n-1]);
			    printf("%d\n",ans);
			}
		}
	}
	return 0;
}
