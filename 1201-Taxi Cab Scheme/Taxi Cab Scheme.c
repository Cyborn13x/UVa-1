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
#define SZ 501

/*problem id-1201
 *Rank - 2 (time0.032 sec)
 *language-ANSI C
 *Maximum Bipartite Matching
 *Theory : same as 1184
 */

int data[SZ][6],AdjList[SZ][SZ],match[SZ],vis[SZ],N;

void Input()
{
      int i,j,t1,t2;
      FORI(i,1,N) AdjList[i][0]=0;
      scanf("%d",&N);
      FORI(i,1,N)
      {
      	scanf("%d:%d %d %d %d %d",&t1,&t2,&data[i][2],&data[i][3],&data[i][4],&data[i][5]);
      	data[i][0]=t1*60+t2, data[i][1]=data[i][0]+abs(data[i][2]-data[i][4])+abs(data[i][3]-data[i][5]);
      }
      FORI(i,1,N)
      {
      	FORI(j,i+1,N)
      	{
      		if(data[i][1]+abs(data[i][4]-data[j][2])+abs(data[i][5]-data[j][3])<data[j][0])
      		{
      		      AdjList[i][++AdjList[i][0]]=j;
      		}
      	}
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
      int i,j,MaxMatch=0;
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
