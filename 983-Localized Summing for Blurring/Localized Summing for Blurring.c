#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 1002
#define ll long long int

/*problem id-983
 *
 *language-ANSI C
 *
 */

int a[SZ][SZ];
ll res,X,data[SZ][SZ];

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
	      if(blank) putchar('\n'); blank=1;
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) scanf("%d",&a[i][j]);
		for(i=1;i<=n;i++) for(j=1;j<=n;j++) data[i][j]=(ll)a[i][j]+data[i-1][j]+data[i][j-1]-data[i-1][j-1];
            for(i=m,res=0;i<=n;i++)
            {
            	for(j=m;j<=n;j++)
            	{
            	      X=(ll)(data[i][j]-data[i-m][j]-data[i][j-m]+data[i-m][j-m]);
            		printf("%lld\n",X);
            		res+=X;
            	}
            }printf("%lld\n",res);
	}
	return 0;
}
