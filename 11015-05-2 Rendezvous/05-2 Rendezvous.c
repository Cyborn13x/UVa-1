#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

int main()
{
	int i,j,k,l,m,n,t,x,y,blank,floyd[23][23],sum,best,person,test=0;
	char name[23][12];
	while(scanf("%d %d",&n,&m) && (n || m))
	{
		for(i=0;i<n;i++) scanf("%s",name[i]);
		for(i=0;i<n;i++) for(j=i+1,floyd[i][i]=0;j<n;j++) floyd[i][j]=floyd[j][i]=1000000;
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d",&x,&y,&l);
			floyd[x-1][y-1]=floyd[y-1][x-1]=l;
		}
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(floyd[i][k]+floyd[k][j]<floyd[i][j])
					{
					      floyd[i][j]=floyd[j][i]=floyd[i][k]+floyd[k][j];
					}
				}
			}
		}
		for(i=0,best=1000000;i<n;i++)
		{
			for(j=sum=0;j<n;j++) sum+=floyd[i][j];
			if(sum<best) best=sum, person=i;
		}
		printf("Case #%d : %s\n",++test,name[person]);
	}
	return 0;
}
