#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 10000000.00

/*problem id-10947
 *
 *language-ANSI C
 *
 */

typedef struct
{
      double x,y,r;
}circle;

int N,path[102][102],flag;
double K,M,floyd[102][102];

double min(double a,double b) { return a<b ? a : b; }

double max(double a,double b) { return a>b ? a : b; }

double dist(circle a,circle b) { return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))-a.r-b.r; }

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	circle list[102],tmp;
	while(scanf("%lf %lf",&K,&M)!=EOF)
	{
		scanf("%lf %lf %lf",&list[0].x,&list[0].y,&list[0].r);
		scanf("%lf %lf %lf",&tmp.x,&tmp.y,&tmp.r);
		scanf("%d",&N); list[N+1]=tmp;
		for(i=1;i<=N;i++) scanf("%lf %lf %lf",&list[i].x,&list[i].y,&list[i].r);
		for(i=0;i<=N+1;i++)
		{
			for(j=i+1;j<=N+1;j++) floyd[i][j]=floyd[j][i]=INF, path[i][j]=path[j][i]=-1;
			floyd[i][i]=0.00;
		}
		for(i=0;i<=N+1;i++) for(j=i+1;j<=N+1;j++) floyd[i][j]=floyd[j][i]=dist(list[i],list[j]);
		for(k=0;k<=N+1;k++)
		{
			for(i=0;i<=N+1;i++)
			{
				for(j=0;j<=N+1;j++)
				{
					floyd[i][j]=min(floyd[i][j],max(floyd[i][k],floyd[k][j]));
				}
			}
		}
		if(floyd[0][N+1]<=(K*M)) printf("Larry and Ryan will escape!\n");
		else printf("Larry and Ryan will be eaten to death.\n");
	}
	return 0;
}
