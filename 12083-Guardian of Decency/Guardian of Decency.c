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
#define SZ1 105

/*problem id-12083
 *
 *language-ANSI C
 *
 */

int adj[SZ][SZ],match[SZ],vis[SZ],h[SZ],N;
char music[SZ][SZ1],hobby[SZ][SZ1],gndr[SZ];

int Check(int x,int y)
{
      if(abs(h[x]-h[y])>40) return 0;
      if(gndr[x]==gndr[y]) return 0;
      if(strcmp(music[x],music[y])) return 0;
      if(!strcmp(hobby[x],hobby[y])) return 0;
      return 1;
}

void Input()
{
      int i,j;
      scanf("%d",&N);
      CLEAR(adj);
      FORI(i,1,N) scanf("%d%*c%c %s %s",&h[i],&gndr[i],music[i],hobby[i]);
      FORI(i,1,N) FORI(j,1,N) if(Check(i,j)) adj[i][j]=1;
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
      int i,j,MaxMatch=0;
      CLEAR(match);
      FORI(i,1,N)
      {
            CLEAR(vis);
            if(DFS(i)) MaxMatch++;
      }
      printf("%d\n",N-(MaxMatch>>1));
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
