#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int n,k,rest,NewBiri,TotalBiri,ans;
	while(scanf("%d %d",&n,&k)==2)
	{
	    TotalBiri=n;
	    ans=n;
	    NewBiri=0;
	    do
	    {
	        rest=TotalBiri%k;
	        NewBiri=(TotalBiri/k);
	        TotalBiri=NewBiri+rest;
	        ans+=NewBiri;
	    }while(TotalBiri>=k);
	    printf("%d\n",ans);
	}
	return 0;
}
