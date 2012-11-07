#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 2147483647
#define MINF -2147483648
#define N 600000

/*problem id-481
 *
 *language-ANSI C
 *
 */

int n;
int num[N];
int I[N+1];
int L[N];
int ans[N];

void LISlogn()
{
      int i;
      int j;
      int t;
      int low;
      int mid;
      int high;
      int LIS_L=0;
      I[0]=MINF;
      for(i=1;i<=n;i++) I[i]=INF;
      for(i=0;i<n;i++)
      {
      	low=0;
      	high=LIS_L;
      	while(low<=high)
      	{
      		mid=(low+high)/2;
      		if(num[i]>I[mid]) low=mid+1;
      		else high=mid-1;
      	}
      	I[low]=num[i]; L[i]=low;
      	if(low>LIS_L) LIS_L=low;
      }
      t=LIS_L;
      printf("%d\n-\n",LIS_L);
      for(i=n-1;i>=0;i--) if(L[i]==t) ans[t--]=num[i];
      for(i=1;i<=LIS_L;i++) printf("%d\n",ans[i]);
      return;
}

int main()
{
	while(scanf("%d",&num[n])==1) n++;
	LISlogn();
	return 0;
}
