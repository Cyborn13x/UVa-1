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

/*problem id-782
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

node grid[40][90];
int a[]={0,0,1,-1};
int b[]={1,-1,0,0};
int len[40];
int level;
int MaxLen;

bool IsValid(int r,int c)
{
    if(r>=0 && r<=level && c>=0 && c<MaxLen+2) return true;
    return false;
}

void DFS(node *n)
{
    int i;
    int r=n->x;
    int c=n->y;
    int xx;
    int yy;
    bool flag=false;
    grid[r][c].state=VISITED;
    for(i=0;i<4;i++)
    {
    	xx=r+a[i];
    	yy=c+b[i];
    	flag = flag || grid[xx][yy].name=='X';
    	if(IsValid(xx,yy) && grid[xx][yy].state==UNVISITED && grid[xx][yy].name==' ') DFS(&grid[xx][yy]);
    }
    grid[r][c].name = flag==true ? '#' : ' ';
    return;
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int t;
	char a[100];
	char c;
	bool fl;

	for(i=0;i<40;i++)for(j=0;j<90;j++){grid[i][j].x=i;grid[i][j].y=j;}
	scanf("%d",&t);
	getchar();
	while(t--)
	{
	    level=-1;
	    MaxLen=0;
	    for(i=0;i<40;i++)
	    {
	        for(j=0;j<90;j++)
	        {
	            grid[i][j].name=' ';
	            grid[i][j].state=UNVISITED;
            }
	    }
		while(gets(a) && a[0]!='_')
		{
		    l=strlen(a);
		    MaxLen = l>MaxLen ? l : MaxLen;
		    level++;
		    len[level]=l;
		    for(i=0;i<l;i++) grid[level][i].name=a[i];
		}
		for(i=0;i<=level;i++)
		{
		    for(j=0;j<len[i];j++)
		    {
		        if(grid[i][j].name=='*' && grid[i][j].state==UNVISITED)
		        {
		            DFS(&grid[i][j]);
		        }
		    }
		}
		for(i=0;i<=level;i++)
		{
		    fl=false;
		    for(j=89;j>=0;j--)
		    {
		        if(grid[i][j].name!=' ')
		        {
		            len[i]=j+1;
		            fl=true;
		            break;
                }
		    }
		    len[i] = fl==true ? len[i] : 0;
		}
		for(i=0;i<=level;i++)
		{
			for(j=0;j<len[i];j++)
			{
			    printf("%c",grid[i][j].name);
			}
			printf("\n");
		}
		printf("%s\n",a);
	}
	return 0;
}
