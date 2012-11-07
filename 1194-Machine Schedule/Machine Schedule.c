#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define Clear(x,y) memset(x,y,sizeof(x))
#define For(x,n) for(x=0;x<n;x++)
#define abs(x) ((x<0)?(-(x)):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long int
#define INF (1<<28)
#define SZ 105

/*Problem ID-1194
 *Rank-2
 *Language-ANSI C
 *
 ********************Algorithm used : Maximum Bipartite Matching********************
 *********************************Explanation***************************************
 *
 *When we find the maximum matching that means we have no other pair of 'free vertex' left between which there is an edge
 *More precisely, let 'm' be the number of maximum match, so every edges are incident to one of the 'm' nodes of LEFT graph
 *or one of the 'm' nodes of RIGHT graph.
 *
 *For this problem we imagine every 'task' as an edge and modes of Machine A is LEFT graph and modes if B is Right graph
 *CLARIFICATION : changing the mode means 'change the mode of both machines to a 'same' mode'
 *NOW , let the matched verteces for LEFT graph are A={1,2,3} and for RIGHT graph B={4,5,6}
 *So every task can be performed by either a node of set A or a node of set B
 *As a result we can change the modes of both machines either to 4,5 and 6
 *or wecan change to 1,2 and 3 . Either way all the task will be performed .
 *
 *NOTE : There is no need to connect a node to node '0'.Because both machines are initially at mode '0'
 *so, node '0' will not be counted in the matching. Although I made edges from/to node '0' but that doesn't
 *effect on the algorithm as I started every loop from '1'.
 * ( খাইছে ! মোটামুটি একটা tutorial লিখে ফেললাম !!! :P )
 */

int AdjMat[SZ][SZ],um[SZ],vm[SZ],vis[SZ],n,m;

int DFS(int u)
{
      int v;
      for(v=1;v<=m;v++)
      {
      	if(AdjMat[u][v] && !vis[v])
      	{
      	      vis[v]=1;
      	      if(!vm[v] || DFS(vm[v]))
      	      {
      	            um[u]=v, vm[v]=u;
      	            return 1;
      	      }
      	}
      }
      return 0;
}

int Hungary(int n)
{
      int i,ret=0;
      Clear(um,0);
      Clear(vm,0);
      for(i=1;i<=n;i++)
      {
            if(!um[i])
            {
                  Clear(vis,0);
                  if(DFS(i)) ret++;
            }
      }
      return ret;
}

int main()
{
	int i,j,k,l,t,x,y,blank=0,test=0;
	while(scanf("%d",&n) && n)
	{
	      Clear(AdjMat,0);
		scanf("%d %d",&m,&k);
		while(k--)
		{
			scanf("%d %d %d",&l,&x,&y);
			AdjMat[x][y]=1;
            }
            printf("%d\n",Hungary(n));
	}
	return 0;
}
