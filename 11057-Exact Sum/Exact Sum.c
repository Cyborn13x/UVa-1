#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define INF 200000000

/*problem id-11057
 *
 *language-ANSI C
 *
 */

int N;
int V;
int a[10005];

int BinarySearch(int low,int high,int n)
{
      int mid;
      while(low<=high)
      {
      	mid=(low+high)/2;
      	if(n>a[mid]) low=mid+1;
      	else if(n==a[mid]) return a[mid];
      	else high=mid-1;
      }
      return -1;
}

int cmp(const void * a,const void *b)
{
      return *(int *)a-*(int *)b;
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
	int ans1;
	int ans2;
	int diff;
	while(scanf("%d",&N)!=EOF)
	{
		for(i=0,diff=INF;i<N;i++) scanf("%d",&a[i]);
		qsort(a,N,sizeof(int),&cmp);
		scanf("%d",&V);
		for(i=0;i<N-1;i++)
		{
			x=a[i], y=V-a[i];
			t=BinarySearch(i+1,N,y);
			if(t!=-1)
			{
			      ans1=x, ans2=y;
			      if(y-x<diff) diff=y-x;
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n",ans1,ans2);
	}
	return 0;
}
