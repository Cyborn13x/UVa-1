#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define INF 1<<30

/*problem id-10803
 *
 *language-ANSI C
 *
 */

typedef struct
{
      int x;
      int y;
}point;

point city[102];
double floyd[102][102];

double Distance(int i,int j)
{
      return ((city[i].x-city[j].x)*(city[i].x-city[j].x)+(city[i].y-city[j].y)*(city[i].y-city[j].y));
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int x;
	int y=1;
	double tmp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d %d",&city[i].x,&city[i].y);
		for(i=0;i<n;i++) for(j=0;j<n;j++) floyd[i][j]=INF;
		for(i=0;i<n;i++) floyd[i][i]=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
			      tmp=Distance(i,j);
			      if(tmp>100) tmp=INF;
			      floyd[i][j]=floyd[j][i]=sqrt(tmp);
			}
		}

		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					tmp=floyd[i][k]+floyd[k][j];
					if(tmp<floyd[i][j]) floyd[i][j]=tmp;
				}
			}
		}
		for(i=0,tmp=0.00;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(floyd[i][j]>tmp) tmp=floyd[i][j];
			}
		}
		printf("Case #%d:\n",y++);
		if(tmp!=sqrt(INF)) printf("%.4lf",tmp);
		else printf("Send Kurdy");
		printf("\n\n");
	}
	return 0;
}
