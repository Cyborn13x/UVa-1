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

/*problem id-12168
 *Rank-16
 *language-ANSI C
 *Maximum Bipartite Matching
 */

int adj[SZ][SZ],match[SZ],vis[SZ],c,d,n;
char in[SZ][5],out[SZ][5];

int Enemy(char *a,char *b,char *c, char *d)
{
      return !strcmp(a,d) || !strcmp(b,c);
}

int DFS(int u)
{
      int i,v;
      FORI(i,1,adj[u][0])
      {
      	v=adj[u][i];
      	if(!vis[v])
      	{
      	      vis[v]=1;
      	      if(match[v]==-1 || DFS(match[v]))
      	      {
      	            match[v]=u, match[u]=v;
      	            return 1;
      	      }
      	}
      }
      return 0;
}

int Hungary()
{
      int i,MaxMatch=0;
      SET(match);
      FOR(i,n)
      {
      	if(match[i]==-1)
      	{
      	      CLEAR(vis);
      	      if(DFS(i)) MaxMatch++;
      	}
      }
      return MaxMatch;
}

int main()
{
	int i,j,k,l,m,t,x,y,z,blank=0,test=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&c,&d,&n);
		FOR(i,n) scanf("%s %s",in[i],out[i]);
		FOR(i,n) adj[i][0]=0;
		FOR(i,n)
		{
			FORI(j,1,n-1)
			{
				if(Enemy(in[i],out[i],in[j],out[j]))
				{
				      adj[i][++adj[i][0]]=j;
				      adj[j][++adj[j][0]]=i;
				}
			}
		}
		printf("%d\n",n-Hungary());
	}
	return 0;
}
