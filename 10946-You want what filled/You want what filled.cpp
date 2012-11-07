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

/*problem id-10946
 *
 *language-C++
 *
 */

using namespace std;

typedef struct
{
    int x;
    int y;
    int access;
    int state;
    char name;
}node;

node grid[50][50];

int row;
int col;
int val;
int a[]={1,-1,0,0};
int b[]={0,0,1,-1};

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
    val++;
    grid[r][c].state=VISITED;
    for(i=0;i<4;i++)
    {
    	xx=r+a[i];
    	yy=c+b[i];
    	if(IsValid(xx,yy) && grid[xx][yy].state==UNVISITED && grid[xx][yy].access==OPEN && grid[xx][yy].name==ch)
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
	int t=0;
	char c;
	vector<int> v;
	map<int,vector<char> > mp;
	for(i=0;i<50;i++) for(j=0;j<50;j++) {grid[i][j].x=i; grid[i][j].y=j;}
	while(scanf("%d %d\n",&row,&col)==2 && row && col)
	{
		v.clear();
		mp.clear();
		for(i=0;i<row;i++) for(j=0;j<col;j++) grid[i][j].state=UNVISITED;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				scanf("%c",&c);
				grid[i][j].name=c;
				grid[i][j].access=(c=='.')?BLOCK:OPEN;
			}
			getchar();
		}
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
			    val=0;
				if(grid[i][j].state==UNVISITED && grid[i][j].access==OPEN)
                {
                    DFS(&grid[i][j]);
                }
                if(val)
                {
                    mp[val].push_back(grid[i][j].name);
                    v.push_back(val);
                }
			}
		}
		printf("Problem %d:\n",++t);
		sort(v.begin(),v.end());
		l=v.size();
		for(i=l-1;i>=0;i--)
		{
			sort(mp[v[i]].begin(),mp[v[i]].end());
			j=mp[v[i]].size();
			for(k=0;k<j;k++) printf("%c %d\n",mp[v[i]][k],v[i]);
			mp[v[i]].clear();
		}
	}
	return 0;
}
