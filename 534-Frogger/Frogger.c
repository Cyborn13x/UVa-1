#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-534
 *
 *language-ANSI C
 *
 */

double mini(double a,double b)
{
      return a<b ? a:b;
}

double maxi(double a,double b)
{
      return a>b ? a:b;
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t=1;
	int x[200];
	int y[200];
	double floyed[200][200];
	double dis;
	while(scanf("%d",&n) && n)
	{
		for(i=0;i<n;i++) scanf("%d %d",&x[i],&y[i]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				floyed[i][j]=99999999.00;
			}
			floyed[i][i]=0;
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				floyed[i][j]=floyed[j][i]=(((x[i]-x[j])*(x[i]-x[j]))+((y[i]-y[j])*(y[i]-y[j])));
			}
		}
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
                              floyed[i][j]=mini(floyed[i][j],maxi(floyed[i][k],floyed[k][j]));
				}
			}
		}
		dis=sqrt(floyed[0][1]);
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",t++,dis);
	}
	return 0;
}
