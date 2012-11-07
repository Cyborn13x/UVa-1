#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 155

/*problem id-10827
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0,a[SZ][SZ],max;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n); x=2*n, max=-INF;
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) scanf("%d",&a[i][j]);
		for(i=1;i<=n;i++) for(j=n+1;j<=x;j++) a[i][j]=a[i][j-n];
		for(i=n+1;i<=x;i++) for(j=1;j<=n;j++) a[i][j]=a[i-n][j];
		for(i=n+1;i<=x;i++) for(j=n+1;j<=x;j++) a[i][j]=a[i-n][j-n];
		for(i=0;i<=x;i++) a[0][i]=a[i][0]=0;
		for(i=1;i<=x;i++) for(j=1;j<=x;j++) a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				for(k=i;k-i<n;k++)
				{
					for(l=j;l-j<n;l++)
					{
						m=a[k][l]-a[i-1][l]-a[k][j-1]+a[i-1][j-1];
						if(m>max) max=m;
					}
				}
			}
		}
		printf("%d\n",max);
	}
	return 0;
}
