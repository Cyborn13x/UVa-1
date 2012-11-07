#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 10002

/*problem id-10534
 *
 *language-ANSI C
 *
 */

int a[SZ],b[SZ],x[SZ],y[SZ],ls[SZ];

int min(int a,int b) { return a<b ? a : b; }

int max(int a,int b) { return a>b ? a : b; }

void LIS(int *ar,int *f,int n)
{
      int i,j,low,mid,high,lislen=0;
      for(i=1,ls[0]=-INF;i<SZ;i++) ls[i]=INF;
      for(i=0;i<n;i++)
      {
      	low=0, high=lislen;
      	while(low<=high)
      	{
      		mid=(low+high)/2;
      		if(ar[i]>ls[mid]) low=mid+1;
      		else high=mid-1;
      	}
      	ls[low]=ar[i];
      	if(low>lislen) lislen=low;
      	f[i]=low;
      }
      return;
}

int main()
{
	int i,j,k,l,m,n,t,blank=0,test=0,res;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			b[n-i-1]=a[i];
		}
		LIS(a,x,n);
		LIS(b,y,n);
		for(i=res=0;i<n;i++) res=max(res,2*min(x[i],y[n-i-1])-1);
		printf("%d\n",res);
	}
	return 0;
}
