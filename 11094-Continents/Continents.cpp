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

#define VISITED 1
#define UNVISITED 0
#define N 30

/*problem id-11094
 *
 *language-C++
 *
 */

using namespace std;

typedef struct
{
    int x;
    int y;
    int color;
    char sign;
}node;

node Grid[N][N];

int m;
int n;
int ans;
int mx;
int a[]={0,0,1,-1};
int b[]={1,-1,0,0};

int IsValid(int xx,int yy)
{
    if(xx>=0 && xx<m && yy>=0 && yy<n) return 1;
    return 0;
}

void DFS(node *nd)
{
    int r=nd->x;
    int c=nd->y;
    char s=nd->sign;
    int xx;
    int yy;
    int i;
    int j;
    ans++;
    nd->color = VISITED;
    for(i=0;i<4;i++)
    {
    	xx=r+a[i];
    	yy=c+b[i];
    	if(IsValid(xx,yy) && Grid[xx][yy].sign==s && Grid[xx][yy].color==UNVISITED)
    	{
    	    DFS(&Grid[xx][yy]);
    	}
    }
    if(c==n-1 && Grid[r][0].sign==s && Grid[r][0].color==UNVISITED) DFS(&Grid[r][0]);
    else if(c==0 && Grid[r][n-1].sign==s && Grid[r][n-1].color==UNVISITED) DFS(&Grid[r][n-1]);
    return;
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int t;
	char a[30];
	char c;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			Grid[i][j].x=i;
			Grid[i][j].y=j;
		}
	}
	while(scanf("%d %d\n",&m,&n)==2)
	{
	    mx=0;
	    ans=0;
	    for(i=0;i<m;i++) for(j=0;j<n;j++) Grid[i][j].color=UNVISITED;

		for(i=0;i<m;i++)
		{
            gets(a);
            for(j=0;a[j]!='\0';j++) Grid[i][j].sign = a[j];
		}
        scanf("%d %d",&k,&l);
        c=Grid[k][l].sign;
        for(i=0;i<m;i++) for(j=0;j<n;j++) if(Grid[i][j].sign!=c) Grid[i][j].color=VISITED;

		DFS(&Grid[k][l]);
		for(i=0;i<m;i++)
		{
		    for(j=0;j<n;j++)
		    {
                if(Grid[i][j].color==UNVISITED)
                {
                    ans=0;
                    DFS(&Grid[i][j]);
                    mx = (ans>mx) ? ans : mx;
                }
		    }
		}
		printf("%d\n",mx);
	}
	return 0;
}
