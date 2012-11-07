#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

/*problem id-11470
 *
 *language-C++
 *
 */

using namespace std;

bool vis[10][10];
int val[10][10];
int n;
int w;

int DFS(int x,int y)
{
      if(vis[x][y]) return 0;
      vis[x][y]=true;
      if(x==w && y<n-w-1) return val[x][y]+DFS(x,y+1);
      else if(x<n-w-1 && y==n-w-1) return val[x][y]+DFS(x+1,y);
      else if(x==n-w-1 && y>w) return val[x][y]+DFS(x,y-1);
      else return val[x][y]+DFS(x-1,y);
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int t;
	int x;
	int y;
	k=0;
	while(scanf("%d",&n)==1 && n)
	{
	      memset(vis,false,sizeof(vis));
		for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&val[i][j]);
		y=ceil(n/2)+(n&1);
		printf("Case %d:",++k);
		for(i=0,w=0;i<y;w++,i++){m=DFS(i,i); printf(" %d",m);}
		printf("\n");
	}
	return 0;
}
