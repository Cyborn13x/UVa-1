#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 20005

/*problem id-11456
 *
 *language-ANSI C
 *
 */

int n,A[SZ],I[SZ+1],LDS[SZ],LIS[SZ];

int max(int a,int b) { return a>b ? a : b; }

void LISlogn(int *a,int c)
{
      int i,j,t,low,mid,high,LIS_L=0;
      if(c) for(i=1,I[0]=-INF;i<=n;i++) I[i]=INF;
      else for(i=1,I[0]=INF;i<=n;i++) I[i]=-INF;
      for(i=0;i<n;i++)
      {
      	low=0, high=LIS_L;
      	while(low<=high)
      	{
      		mid=(low+high)>>1;
      		if((A[i]>I[mid])==c) low=mid+1;
      		else high=mid-1;
      	}
      	I[low]=A[i], a[i]=low;
      	if(low>LIS_L) LIS_L=low;
      }
      return;
}

int main()
{
	int i,j,k,l,m,t,x,y,res,blank=0,test=0;
      scanf("%d",&t);
      while(t--)
      {
      	scanf("%d",&n);
      	for(i=0;i<n;i++) scanf("%d",&A[i]);
      	for(i=0;i<n/2;i++) x=A[i], A[i]=A[n-i-1], A[n-i-1]=x;
      	LISlogn(LIS,1);
      	LISlogn(LDS,0);
      	for(i=res=0;i<n;i++) res=max(res,LIS[i]+LDS[i]-1);
      	printf("%d\n",res);
      }
	return 0;
}
