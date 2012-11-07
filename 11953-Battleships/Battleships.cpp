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
#define N 120

/*problem id-11953
 *
 *language-C++
 *
 */

using namespace std;

int row;
int a[]={0,0,1,-1};
int b[]={1,-1,0,0};
char ar[N][N];

bool IsValid(int r,int c)
{
    if(r>=0 && r<row && c>=0 && c<row) return 1;
    return 0;
}

void DFS(int r,int c)
{
    int i;
    int xx;
    int yy;
    ar[r][c]='.';
    for(i=0;i<4;i++)
    {
    	xx=r+a[i];
    	yy=c+b[i];
    	if(IsValid(xx,yy) && ar[xx][yy]!='.')
    	{
    	    DFS(xx,yy);
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
	int m;
	int n;
	int t;
	int counter;
	scanf("%d",&t);
	while(t--)
    {
	    counter=0;
	    scanf("%d",&row);
		for(i=0;i<row;i++) scanf("%s",ar[i]);
		for(i=0;i<row;i++)
		{
			for(j=0;j<row;j++)
			{
				if(ar[i][j]=='x')
				{
				    counter++;
				    DFS(i,j);
				}
			}
		}
		printf("Case %d: %d\n",++k,counter);
	}
	return 0;
}

