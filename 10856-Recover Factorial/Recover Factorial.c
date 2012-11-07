#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 100000
#define ll long long int
#define N 2742823

/*problem id-10856
 *
 *language-ANSI C
 *
 */

int factor[N],data[N];

void SieveFactor()
{
      int i,j,k;
      for(i=2,factor[1]=1;i<N;i++)
      {
      	if(!factor[i]) factor[i]=1;
      	for(j=2;(k=i*j)<N && j<=i;j++) if(factor[j]==1) factor[k]=factor[i]+1;
      }
      return;
}

int cmp(const void *a,const void *b)
{
      return *((int *)a)-*((int *)b);
}

void Precal()
{
      int i,flag=0;
      SieveFactor();
      data[0]=data[1]=0;
      for(i=2;i<N;i++) data[i]=data[i-1]+factor[i];
      return;
}

int BinarySearch(int val)
{
      int low=0,high=N-1,mid;
      if(!val) return 0;
      while(low<=high)
      {
      	mid=(low+high)>>1;
      	if(val>data[mid]) low=mid+1;
      	else if(val<data[mid]) high=mid-1;
      	else return mid;
      }
      return -1;
}

int main()
{
	int n,x,test=0;
	Precal();
	while(scanf("%d",&n) && n>=0)
	{
		if((x=BinarySearch(n))==-1) printf("Case %d: Not possible.\n",++test);
		else printf("Case %d: %d!\n",++test,x);
	}
	return 0;
}
