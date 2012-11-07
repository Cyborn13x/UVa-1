#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cmath>
#include <ctime>
#include <string>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

#define Clear(x,y) memset(x,y,sizeof(x))
#define For(x,n) for(x=0;x<n;x++)
#define abs(x) ((x<0)?(-(x)):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long int
#define INF 1<<28
#define SZ 1005

/*problem id-610
 *
 *language-C++
 *
 */

using namespace std;

int p[SZ],n;
bool AdjMat[SZ][SZ],vis[SZ];

void DFS(int u)
{
      int v,pre;
      vis[u]=1;
      For(v,n)
      {
      	if(AdjMat[u][v])
      	{
      	      if(!vis[v]) { p[v]=u; DFS(v); }
      	      else if(vis[v] && v!=p[u])
      	      {
      	            AdjMat[v][u]=0, pre=u;
      	            while(pre!=v)
      	            {
      	            	AdjMat[pre][p[pre]]=0;
      	            	pre=p[pre];
      	            }
      	      }
      	}
      }
      return;
}

int main()
{
	int i,j,k,l,m,t,x,y,blank,test=0;
	while(scanf("%d %d",&n,&m) && (n || m))
	{
		Clear(p,-1);
		Clear(vis,0);
		Clear(AdjMat,0);
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&x,&y);
			x--, y--;
			AdjMat[x][y]=AdjMat[y][x]=1;
		}
		DFS(0);
		printf("%d\n\n",++test);
		For(i,n) For(j,n) if(AdjMat[i][j]) printf("%d %d\n",i+1,j+1);
		printf("#\n");
	}
	return 0;
}
