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
#define SZ 1002
#define SZ1 102

/*problem id-10092
 *
 *language-ANSI C
 *
 */

int adj[SZ][SZ1],match[SZ1],nk,np,p[22],link[SZ1],cum[22],vis[SZ1],sum;

int DFS(int u)
{
      int v;
      FORI(v,1,sum)
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

int cmp(const void *a,const void *b)
{
      return *(int *)a-*(int *)b;
}

void Hungary()
{
      int i,j,x,MaxMatch=0,tmp[102];
      CLEAR(match);
      FORI(i,1,np)
      {
      	CLEAR(vis);
      	if(DFS(i)) MaxMatch++;
      }
      if(MaxMatch!=sum)
      {
            printf("0\n");
            return;
      }printf("1\n");
      FORI(i,1,nk)
      {
      	x=0;
      	FORI(j,cum[i-1]+1,cum[i]) tmp[x++]=match[j];
      	qsort(tmp,x,sizeof(int),&cmp);
      	FOR(j,x)
      	{
      		if(j) putchar(' ');
      		printf("%d",tmp[j]);
      	}printf("\n");
      }
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,z,blank=0,test=0;
	while(scanf("%d %d",&nk,&np) && (nk || np))
	{
	      cum[0]=0;
	      CLEAR(adj);
		FORI(i,1,nk)
		{
		      scanf("%d",&p[i]);
		      cum[i]=cum[i-1]+p[i];
		}sum=cum[i-1];
		FORI(i,1,np)
		{
			scanf("%d",&x);
			FOR(j,x)
			{
			      scanf("%d",&y);
			      FORI(k,cum[y-1]+1,cum[y]) adj[i][k]=1;
			}
		}
		Hungary();
	}
	return 0;
}
