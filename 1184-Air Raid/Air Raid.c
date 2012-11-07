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
#define SZ 122

/**************************** RANK #1 ***********************************
 *problem id-1184
 *Rank - 1 (Time 0.012 sec)
 *language-ANSI C
 *
 *Maximum Bipartite Matching
 *
 * RANK #1 পাইয়া মনে হইতাছে হওয়ায় ভাসতাছি !!! মনে ব্যাপক আনন্দ !!!
 *
 */

 /*Theory : If I can match a node with another node that means I can use
  *the same 'paratroopers'(alien ship) for both nodes.
  *So, as long as I can find a matching(add an edge) i can reduce the number of
  *'paratroopers'. The finale answer will be then N-MaxMatch.
  */

int AdjList[SZ][SZ],match[SZ],vis[SZ],N,M;

void Input()
{
      int i,x,y;
      scanf("%d %d",&N,&M);
      FORI(i,1,N) AdjList[i][0]=0;
      while(M--)
      {
      	scanf("%d %d",&x,&y);
      	AdjList[x][++AdjList[x][0]]=y;
      }
      return;
}

int DFS(int u)
{
      int i,v;
      FORI(i,1,AdjList[u][0])
      {
      	v=AdjList[u][i];
      	if(!vis[v])
      	{
      	      vis[v]=1;
      	      if(!match[v] || DFS(match[v]))
      	      {
      	            match[v]=u;
      	            return 1;
      	      }
      	}
      }
      return 0;
}

void Hungary()
{
      int i,MaxMatch=0;
      CLEAR(match);
      FORI(i,1,N)
      {
      	CLEAR(vis);
      	if(DFS(i)) MaxMatch++;
      }
      printf("%d\n",N-MaxMatch);
      return;
}

int main()
{
	int t;
      scanf("%d",&t);
      while(t--)
      {
      	Input();
      	Hungary();
      }
	return 0;
}
