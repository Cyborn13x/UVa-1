#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define INF 2147483647
#define MINF -2147483648
#define N 100000

/*problem id-497
 *
 *language-ANSI C
 *
 */

int n;
int A[N];
int I[N+1];
int L[N];
int LIS[N];

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
      		if(A[i]>I[mid]) low=mid+1;
      		else high=mid-1;
      	}
      	I[low]=A[i]; L[i]=low;
      	if(low>LIS_L) LIS_L=low;
      }
      t=LIS_L;
      printf("Max hits: %d\n",LIS_L);
      for(i=n-1;i>=0;i--) if(L[i]==t) LIS[t--]=A[i];
      for(i=1;i<=LIS_L;i++) printf("%d\n",LIS[i]);
      return;
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int t;
	int x;
	int y;
	int blank=0;
	char a[30];
      scanf("%d",&t);
      getchar();
      gets(a);
      while(t--)
      {
      	if(blank) printf("\n");
      	blank=1,x=0;
      	while(gets(a) && strlen(a)) A[x++]=atoi(a);
      	n=x; LISlogn();
      }
	return 0;
}
