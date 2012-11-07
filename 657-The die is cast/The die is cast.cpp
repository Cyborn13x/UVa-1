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

/*problem id-657
 *
 *language-C++
 *
 */

using namespace std;

int row;
int col;
int cnt;
int a[]={1,-1,0,0};
int b[]={0,0,1,-1};
char grid[55][55];

void DFSX(int r,int c)
{
    if(r<0 || c<0 || r>=row || c>=col || grid[r][c]!='X') return;
    grid[r][c]='*';
    for(int i=0;i<4;i++)
    {
    	DFSX(r+a[i],c+b[i]);
    }
    return;
}

void DFS(int r,int c)
{
    if(r<0 || c<0 || r>=row || c>=col || grid[r][c]=='.') return;
    if(grid[r][c]=='X')
    {
        cnt++;
        DFSX(r,c);
    }
    grid[r][c]='.';
    for(int i=0;i<4;i++)
    {
    	DFS(r+a[i],c+b[i]);
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
	bool flag=false;
	vector<int> v;
	k=1;
    while(scanf("%d %d",&col,&row)==2 && row && col)
    {
        for(i=0;i<row;i++) scanf("%s",grid[i]);
        v.clear();
        for(i=0;i<row;i++)
        {
        	for(j=0;j<col;j++)
        	{
        		if(grid[i][j]!='.')
        		{
        		    cnt=0;
        		    DFS(i,j);
                    v.push_back(cnt);
        		}
        	}
        }
        sort(v.begin(),v.end());
        l=v.size();
        printf("Throw %d\n%d",k++,v[0]);
        for(i=1;i<l;i++) printf(" %d",v[i]);
        printf("\n\n");
    }
    return 0;
}
