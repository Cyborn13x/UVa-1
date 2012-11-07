#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int f91(int n)
{
    if(n<=100)
    {
        return f91(f91(n+11));
    }
    else
    {
        return  (n-10);
    }
}

int main()
{
	int n,ans;
	while(1)
	{
	    scanf("%d",&n);
	    if(n==0) break;
	    ans=f91(n);
	    printf("f91(%d) = %d\n",n,ans);
	}
	return 0;
}
