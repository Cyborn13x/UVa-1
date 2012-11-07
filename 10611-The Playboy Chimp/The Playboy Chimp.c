#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-10611
 *
 *language-ANSI C
 *
 */

int left,right;
long long int data[50005],value;

void BinarySearch(int low,int high)
{
      int i,mid;
      while(low<=high)
      {
            mid=(low+high)/2;
      	if(value==data[mid])
      	{
      	      i=mid;
      	      while(data[i+1]==value) i++;
      	      right=i+1;
      	      i=mid;
      	      while(data[i-1]==value) i--;
      	      left=i-1;
      	      return;
      	}
      	else if(value>data[mid])
      	{
      	      if(value<data[mid+1])
      	      {
      	            left=mid, right=mid+1;
      	            return;
      	      }
      	      low=mid+1;
      	}
      	else
      	{
      	      if(value>data[mid-1])
      	      {
      	            left=mid-1, right=mid;
      	            return;
      	      }
      	      high=mid-1;
      	}
      }
}

int main()
{
	int i,j,k,l,m,n,t,x,y,q,blank,test=0;
	scanf("%d",&n);
	data[0]=-8589934592, data[n+1]=8589934592;
	for(i=1;i<=n;i++) scanf("%lld",&data[i]);
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		scanf("%lld",&value);
		BinarySearch(1,n);
		left ? printf("%lld ",data[left]) : printf("X ");
		right==n+1 ? printf("X\n",data) : printf("%lld\n",data[right]);
	}
	return 0;
}
