#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int f(int n)
{
    int sum=0;
    if(n<10)
    {
        return n;
    }
    while(1)
    {
        sum+=n%10;
        n/=10;
        if(n==0)
        {
            sum+=n;
            return sum;
        }
    }
}

int g(int n)
{
    if(n/10==0)
    {
        return n;
    }
    while(n/10!=0)
    {
        n=f(n);
    }
    return n;
}

int main()
{
	int n;
	while(1)
	{
	    scanf("%d",&n);
	    if(!n)
	    {
	        break;
	    }
	    printf("%d\n",g(n));
	}
	return 0;
}
