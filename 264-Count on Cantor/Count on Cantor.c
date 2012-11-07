#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define N 4475

int sum[N];

int BinarySearch(int low,int high,int val)
{
      int mid;
      while(low<=high)
      {
      	mid=(low+high)/2;
      	if(val>sum[mid])
      	{
      	      low=mid+1;
      	      if(val<sum[mid+1]) return mid+1;
      	}
      	else  if(val==sum[mid]) return mid;
      	else
      	{
      	      high=mid-1;
      	      if(val>sum[mid-1]) return mid;
      	}
      }
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank,test=0,extra;
	for(i=1;i<N;i++) sum[i]+=i+sum[i-1];
	while(scanf("%d",&n)!=EOF)
	{
		x=BinarySearch(0,N,n);
		extra=n-sum[x-1]-1;
		if(x&1) printf("TERM %d IS %d/%d\n",n,x-extra,1+extra);
		else printf("TERM %d IS %d/%d\n",n,1+extra,x-extra);
	}
	return 0;
}
