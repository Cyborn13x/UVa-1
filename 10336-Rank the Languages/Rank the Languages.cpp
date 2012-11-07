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

/*problem id-10336
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
	int m;
	int n;
	int t;
	char c;
	vector<int> v;
	vector<int>::iterator it1;
	map<char,int> mp;
	map<char,int>::iterator it;
	map<int,vector<char> > mp1;
	for(i=0;i<100;i++) for(j=0;j<100;j++) {grid[i][j].x=i; grid[i][j].y=j;}
	scanf("%d",&t);
	for(m=0;m<t;m++)
	{
	    scanf("%d %d\n",&row,&col);
		v.clear();
		mp.clear();
		mp1.clear();
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
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				if(grid[i][j].state==UNVISITED)
                {
                    DFS(&grid[i][j]);
                    mp[grid[i][j].name]++;
                }
			}
		}
		for(it=mp.begin();it!=mp.end();it++)
		{
		    c=(*it).first;
		    n=(*it).second;
			mp1[n].push_back(c);
			v.push_back(n);
		}
		sort(v.begin(),v.end());
		it1=unique(v.begin(),v.end());
		v.resize(it1-v.begin());
		printf("World #%d\n",m+1);
		l=v.size();
		for(i=l-1;i>=0;i--)
		{
			sort(mp1[v[i]].begin(),mp1[v[i]].end());
			j=mp1[v[i]].size();
			for(k=0;k<j;k++) printf("%c: %d\n",mp1[v[i]][k],v[i]);
			mp1[v[i]].clear();
		}
	}
	return 0;
}
