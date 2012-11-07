#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define clear(x,y) memset(x,y,sizeof(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long int
#define INF 1<<20
#define SZ 102

/*problem id-12319
 *
 *language-ANSI C
 *
 */

int a[SZ][SZ],b[SZ][SZ],n;

int OK(int A,int B)
{
      int i,j,x,y;
      for(i=0;i<n;i++)
      {
      	for(j=0;j<n;j++)
      	{
      		if((x=b[i][j])>=INF) return 0;
      		y=A*a[i][j]+B;
      		if(x>y) return 0;
      	}
      }
      return 1;
}

int main()
{
	int i,j,k,l,m,t,x,y,A,B,blank=0,test=0;
	char line[2000],*p;
	while(scanf("%d%*c",&n) && n)
	{
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				a[i][j]=a[j][i]=b[i][j]=b[j][i]=INF;
			}
			a[i][i]=b[i][i]=0;
		}
		for(i=0;i<n;i++)
		{
			gets(line);
			p=strtok(line," ");
			x=atoi(p);
			p=strtok(NULL," ");
			while(p!=NULL)
			{
				y=atoi(p);
				a[x-1][y-1]=1;
				p=strtok(NULL," ");
			}
		}
		for(i=0;i<n;i++)
		{
			gets(line);
			p=strtok(line," ");
			x=atoi(p);
			p=strtok(NULL," ");
			while(p!=NULL)
			{
				y=atoi(p);
				b[x-1][y-1]=1;
				p=strtok(NULL," ");
			}
		}
		scanf("%d %d",&A,&B);
		if(!A && !B && n>1) { puts("No"); continue; }
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(a[i][k]+a[k][j]<a[i][j])
					{
					      a[i][j]=a[i][k]+a[k][j];
					}
					if(b[i][k]+b[k][j]<b[i][j])
					{
					      b[i][j]=b[i][k]+b[k][j];
					}
				}
			}
		}
		if(OK(A,B)) puts("Yes");
		else puts("No");
	}
	return 0;
}
