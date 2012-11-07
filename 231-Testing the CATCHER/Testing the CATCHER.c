#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define INF 2147483647
#define MINF -2147483648
#define N 1000000

/*problem id-231
 *
 *language-ANSI C
 *
 */

int A[N];
int I[N+1];

void LIS(int n)
{
      int i;
      int j;
      int len=0;
      int low;
      int mid;
      int high;
      I[0]=INF;
      for(i=1;i<=N;i++) I[i]=MINF;
      for(i=0;i<n;i++)
      {
      	low=0;
      	high=len;
      	while(low<=high)
      	{
      	      mid=(low+high)/2;
      		if(A[i]<I[mid]) low=mid+1;
      		else high=mid-1;
      	}
      	I[low]=A[i];
      	if(len<low) len=low;
      }
      printf("  maximum possible interceptions: %d\n",len);
      return;
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int x;
	int y;
	int blank=0; k=1,n=0;
      while(scanf("%d",&A[n]) && A[n]!=-1)
      {
            if(blank) printf("\n");
            blank=1,n++; printf("Test #%d:\n",k++);
      	while(scanf("%d",&A[n]) && A[n]!=-1) n++;
      	LIS(n); n=0;
      }
	return 0;
}
