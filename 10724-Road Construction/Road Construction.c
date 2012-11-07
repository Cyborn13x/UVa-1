#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 55

/*problem id-10724
 *
 *language-ANSI C
 *
 */

double xx[SZ],yy[SZ],floyd[SZ][SZ];
int AdjMat[SZ][SZ],n,m;

double min(double a,double b) { return a<b ? a : b; }

double dis(int i,int j)
{
      return sqrt((xx[i]-xx[j])*(xx[i]-xx[j])+(yy[i]-yy[j])*(yy[i]-yy[j]));
}

void init()
{
      int i,j;
      for(i=1;i<=n;i++)
      {
      	for(j=1;j<=n;j++)
      	{
      		AdjMat[i][j]=0;
      		floyd[i][j]=(double)(INF);
      	}
      	floyd[i][i]=0;
      }
      return;
}

void FloydWarshall()
{
      int i,j,k;
      for(k=1;k<=n;k++)
      {
      	for(i=1;i<=n;i++)
      	{
      		for(j=1;j<=n;j++)
      		{
      			floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
      		}
      	}
      }
      return;
}

double FindProfit(int u,int v,double d)
{
      int i,j;
      double ret=0,dif,d1,d2,mn;
      for(i=1;i<=n;i++)
      {
      	for(j=i+1;j<=n;j++)
      	{
                  d1=floyd[i][u]+d+floyd[v][j];
                  d2=floyd[i][v]+d+floyd[u][j];
                  mn=min(d1,d2);
                  dif=floyd[i][j]-mn;
                  if(dif>0) ret+=dif;
      	}
      }
      return ret;
}

void Calculation()
{
      int i,j,k,str,end,flag=0;
      double tmp,maxprofit=0,mindis=(double)(INF),profit;
      FloydWarshall();
      for(i=1;i<=n;i++)
      {
      	for(j=i+1;j<=n;j++)
      	{
      		if(AdjMat[i][j]) continue;
      		profit=FindProfit(i,j,tmp=dis(i,j));
      		if(profit<=1) continue;
                  if(profit>maxprofit) maxprofit=profit, mindis=tmp, str=i, end=j, flag=1;
                  else if(profit==maxprofit && tmp<mindis) mindis=tmp, str=i, end=j, flag=1;
      	}
      }
      if(!flag) printf("No road required\n");
      else printf("%d %d\n",str,end);
}

int main()
{
	int i,j,k,l,t,x,y,blank=0,test=0;
	while(scanf("%d %d",&n,&m) && (n || m))
	{
	      init();
		for(i=1;i<=n;i++) scanf("%lf %lf",&xx[i],&yy[i]);
		for(i=1;i<=m;i++)
		{
		      scanf("%d %d",&x,&y);
		      floyd[x][y]=floyd[y][x]=dis(x,y);
		      AdjMat[x][y]=AdjMat[y][x]=1;
            }
		Calculation();
	}
	return 0;
}
