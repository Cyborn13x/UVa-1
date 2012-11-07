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
#define SZ 102

/*problem id-10080
 *
 *language-ANSI C
 *
 */

int AdjMat[SZ][SZ],vis[SZ],left[SZ],right[SZ],n,m;

double dis(double x1,double y1,double x2,double y2)
{
      return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int DFS(int u)
{
      int v;
      for(v=1;v<=m;v++)
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

int Hungary()
{
      int i,ret=0;
      Clear(left,0);
      Clear(right,0);
      for(i=1;i<=n;i++)
      {
      	if(!left[i])
      	{
      	      Clear(vis,0);
      	      if(DFS(i)) ret++;
      	}
      }
      return ret;
}

int main()
{
	int i,j,k,l,t,s,v,x,y,blank=0,test=0;
	double gopher[SZ][2],hole[SZ][2],D;
	while(scanf("%d %d %d %d",&n,&m,&s,&v)!=EOF)
	{
	      Clear(AdjMat,0); D=(double)(s*v);
            For(i,n) scanf("%lf %lf",&gopher[i][0],&gopher[i][1]);
		For(i,m) scanf("%lf %lf",&hole[i][0],&hole[i][1]);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(dis(gopher[i-1][0],gopher[i-1][1],hole[j-1][0],hole[j-1][1])<=D)
				{
				      AdjMat[i][j]=1;
				}
			}
		}
		printf("%d\n",n-Hungary());
	}
	return 0;
}
