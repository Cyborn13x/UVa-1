#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define CLEAR(x) memset(x,0,sizeof(x))
#define SET(x) memset(x,-1,sizeof(x))
#define FORI(x,y,n) for(x=(y);x<=(n);x++)
#define FOR(x,n) for(x=0;x<(n);x++)
#define abs(x) ((x<0)?(-(x)):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define llu unsigned long long int
#define ll long long int
#define INF (1<<28)
#define SZ 502

/*problem id-11138
 *
 *language-ANSI C
 *
 *Maximum Bipartite Matching ( Hungarian Algorithm )
 *
 */

int AdjMat[SZ][SZ],left[SZ],right[SZ],vis[SZ],bolt,nut;

void Input()
{
      int i,j;
      scanf("%d %d",&bolt,&nut);
      FORI(i,1,bolt) FORI(j,1,nut) scanf("%d",&AdjMat[i][j]);
      return;
}

int DFS(int u)
{
      int v;
      FORI(v,1,nut)
      {
      	if(AdjMat[u][v] && !vis[v])
      	{
      	      vis[v]=1;
      	      if(!right[v] || DFS(right[v]))
      	      {
      	            left[u]=v, right[v]=u;
      	            return 1;
      	      }
      	}
      }
      return 0;
}

void Hungary(int test)
{
      int i,MaxMatch=0;
      CLEAR(left);
      CLEAR(right);
      FORI(i,1,bolt)
      {
      	if(!left[i])
      	{
      	      CLEAR(vis);
      	      if(DFS(i)) MaxMatch++;
      	}
      }
      printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",test,MaxMatch);
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	scanf("%d",&t);
	while(t--)
	{
		Input();
		Hungary(++test);
	}
	return 0;
}
