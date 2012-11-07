#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 100000
#define ll long long int

/*problem id-11790
 *
 *language-ANSI C
 *
 */

int a[SZ],w[SZ],data[SZ];

int max(int a,int b) { return a>b ? a : b; }

int LIS(int n)
{
      int i,j,ret=0;
      for(i=0;i<n;i++)
      {
            data[i]=w[i];
      	for(j=0;j<i;j++)
      	{
      		if(a[j]<a[i] && data[j]+w[i]>data[i])
      		{
      		      data[i]=data[j]+w[i];
      		}
      	}
      }
      for(i=0;i<n;i++) ret=max(ret,data[i]);
      return ret;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<n;i++) scanf("%d",&w[i]);
		x=LIS(n);
		for(i=0;i<(n>>1);i++) k=a[i], a[i]=a[n-i-1], a[n-i-1]=k;
		for(i=0;i<(n>>1);i++) k=w[i], w[i]=w[n-i-1], w[n-i-1]=k;
		y=LIS(n);
		if(x>=y) printf("Case %d. Increasing (%d). Decreasing (%d).\n",++test,x,y);
		else printf("Case %d. Decreasing (%d). Increasing (%d).\n",++test,y,x);
	}
	return 0;
}
