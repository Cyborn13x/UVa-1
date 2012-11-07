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

/*problem id-11110
 *
 *language-C++
 *
 */

using namespace std;

int n;
int row;
int grid[110][110];
int a[]={0,0,1,-1};
int b[]={1,-1,0,0};
int cnt;
bool vis[110][110];
char s[5000];

void DFS(int r,int c,int v)
{
    if(r<0 || c<0 || r>=n || c>=n || vis[r][c] || grid[r][c]!=v) return;
    int i;
    vis[r][c]=true;
    cnt++;
    for(i=0;i<4;i++) DFS(r+a[i],c+b[i],grid[r][c]);
    return;
}

void solve()
{
    int i;
    int j;
    bool flag=true;
    memset(vis,false,sizeof(vis));
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		if(!vis[i][j])
    		{
    		    cnt=0;
    		    DFS(i,j,grid[i][j]);
    		    if(cnt!=n) flag=false;
            }
    	}
    }
    if(!flag) printf("wrong\n");
    else printf("good\n");
    return;
}

void build(int i)
{
    char *ptr;
    int x;
    int y;
    ptr=strtok(s," ");
    while(ptr!=NULL)
    {
    	x = atoi(ptr);
    	ptr = strtok(NULL," ");
    	y = atoi(ptr);
    	ptr = strtok(NULL," ");
    	grid[x-1][y-1] = i;
    }
    return;
}

int main()
{
	int i;
	int j;
	int l;
	int m;
	int t;
	while(scanf("%d",&n)==1 && n)
	{
	    getchar();
	    memset(grid,0,sizeof(grid));
	    for(i=1;i<n;i++)
	    {
	    	gets(s);
	    	build(i);
	    }
	    for(i=0;i<n;i++) for(j=0;j<n;j++) if(!grid[i][j]) grid[i][j] = n;
	    solve();
	}
	return 0;
}
