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
#define SZ 102

/*problem id-11159
 *Rank-17
 *language-ANSI C
 *
 *Key concept : if b[i]%a[i]==0 then I made an edge from 'i' to 'j'
 *Note : if a[i]==0 then b[i]%a[i]==0 gets RTE , so it should be cheacked separately and
 *also ' 0 is a multiple of 0 . so if a[i] and b[j] both are 0 then it's a valid edge. '
 *
 */

int AdjList[SZ][SZ],left[SZ],right[SZ],vis[SZ],a[SZ],b[SZ],N,M;

int DFS(int u)
{
      int v;
      FORI(v,1,M)
      {
            if(AdjList[u][v] && !vis[v])
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

int Hungary()
{
      int i,j,ret=0;
      CLEAR(left);
      CLEAR(right);
      FORI(i,1,N)
      {
      	if(!left[i])
      	{
      	      CLEAR(vis);
      	      if(DFS(i)) ret++;
      	}
      }
      return ret;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	scanf("%d",&t);
	while(t--)
	{
	      CLEAR(AdjList);
	      scanf("%d",&N);
		FORI(i,1,N) scanf("%d",&a[i]);
		scanf("%d",&M);
		FORI(i,1,M) scanf("%d",&b[i]);
		FORI(i,1,N) FORI(j,1,M) if((!a[i] && !b[j]) || (a[i] && b[j]%a[i]==0)) AdjList[i][j]=j;
		printf("Case %d: %d\n",++test,Hungary());
	}
	return 0;
}
