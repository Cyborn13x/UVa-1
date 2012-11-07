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

/*problem id-670
 *
 *language-ANSI C
 *
 *Maximum Bipartite matching
 *
 *I ran Hungarian Algorithm through the graph and
 *the 'interesting places' (mode precisely the 'matched nodes') were saved in the array 'left'.
 *
 */

int AdjMat[SZ][SZ],point[SZ][2],place[SZ][2],left[SZ],right[SZ],vis[SZ],N,M;

double dis(double x1,double y1,double x2,double y2)
{
      return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void Input()
{
      int i,j;
      double d1,d2;
      CLEAR(AdjMat);
      scanf("%d %d",&N,&M);
      FORI(i,1,N) scanf("%d %d",&point[i][0],&point[i][1]);
      FORI(i,1,M) scanf("%d %d",&place[i][0],&place[i][1]);
      FORI(i,1,N-1)
      {
            d1=2.0*dis(point[i][0],point[i][1],point[i+1][0],point[i+1][1]);
      	FORI(j,1,M)
      	{
      		d2=dis(point[i][0],point[i][1],place[j][0],place[j][1]);
      		d2+=dis(place[j][0],place[j][1],point[i+1][0],point[i+1][1]);
      		if(d2<=d1) AdjMat[i][j]=1;
      	}
      }
      return;
}

int DFS(int u)
{
      int v;
      FORI(v,1,M)
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

void Hungary()
{
      int i,j,k,l,ret=0,tmp[SZ];
      CLEAR(left);
      CLEAR(right);
      FORI(i,1,N-1)
      {
      	if(!left[i])
      	{
      	      CLEAR(vis);
      	      if(DFS(i)) ret++;
      	}
      }printf("%d\n",N+ret);
      FORI(i,1,N)
      {
            if(i>1) printf(" ");
      	printf("%d %d",point[i][0],point[i][1]);
      	if(left[i]) printf(" %d %d",place[left[i]][0],place[left[i]][1]);
      }printf("\n");
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	scanf("%d",&t);
	while(t--)
	{
	      if(blank) printf("\n");
	      blank=1;
		Input();
		Hungary();
	}
	return 0;
}
