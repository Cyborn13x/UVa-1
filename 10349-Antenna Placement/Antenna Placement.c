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
#define SZ 402

/*problem id-10349
 *
 *language-ANSI C
 *
 *Maximum Bipartite Matching
 */
const int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};
int adj[SZ][SZ],match[SZ],id[42][12],vis[SZ],h,w,N;
char a[42][12];

void Input()
{
      int i,j,k,x,y;
      CLEAR(adj); N=0;
      scanf("%d %d",&h,&w);
      FOR(i,h) scanf("%s",a[i]);
      FOR(i,h) FOR(j,w) if(a[i][j]=='*') id[i][j]=++N;
      FOR(i,h)
      {
      	FOR(j,w)
      	{
      		if(a[i][j]=='*')
      		{
      		      FOR(k,4)
      		      {
      		      	x=i+dx[k], y=j+dy[k];
      		      	if(x<0 || x>=h || y<0 || y>=w || a[x][y]!='*') continue;
      		      	adj[id[i][j]][id[x][y]]=1;
      		      }
      		}
      	}
      }
      return;
}

int DFS(int u)
{
      int v;
      FORI(v,1,N)
      {
      	if(adj[u][v] && !vis[v])
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
      printf("%d\n",N-(MaxMatch>>1));
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
