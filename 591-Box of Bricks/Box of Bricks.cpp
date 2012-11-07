#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int a[50],i,j=0,n,moves,h,sum;
	while(scanf("%d",&n) && n)
	{
	    j++;
	    sum=0;
	    for(i=0;i<n;i++)
	    {
	    	scanf("%d",&a[i]);
	    	sum+=a[i];
	    }
	    h=sum/n;
	    moves=0;
	    for(i=0;i<n;i++)
	    {
	    	if(a[i]>h)
	    	{
	    	    moves+=(a[i]-h);
	    	}
	    }
	    printf("Set #%d\nThe minimum number of moves is %d.\n\n",j,moves);
	}
	return 0;
}
