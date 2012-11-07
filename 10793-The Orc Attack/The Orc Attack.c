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
#define SZ 101

/*problem id-10793
 *
 *language-ANSI C
 *
 */

int fw[SZ][SZ],N;

int Check(int n)
{
      int i;
      FORI(i,2,5) if(fw[i][n]!=fw[i-1][n] || fw[i][n]==INF) return 0;
      return 1;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,z,blank=0,test=0,flag,mn,mx;
	scanf("%d",&t);
	while(t--)
	{
	      flag=0, mn=INF;
		scanf("%d %d",&N,&m);
		FORI(i,1,N)
		{
			FORI(j,1,N) fw[i][j]=INF;
			fw[i][i]=0;
		}
		while(m--)
		{
			scanf("%d %d %d",&x,&y,&z);
			fw[x][y]=fw[y][x]=min(fw[x][y],z);
		}
		FORI(k,1,N) FORI(i,1,N) FORI(j,1,N) fw[i][j]=min(fw[i][j],fw[i][k]+fw[k][j]);
		FORI(i,6,N)
		{
			if(Check(i))
			{
			      mx=-INF;
			      FORI(j,1,N) mx=max(mx,fw[i][j]);
			      mn=min(mn,mx);
			}
		}printf("Map %d: %d\n",++test,mn==INF ? -1 : mn);
	}
	return 0;
}
