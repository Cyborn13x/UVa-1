#include<stdio.h>
#include<stdlib.h>

int main()
{
	long long int i,j,n;
	int a[100000];
	while(1)
	{
	    scanf("%lld",&n);
	    if(n<0)
	    {
	        break;
	    }
	    if(n==0)
	    {
	        printf("0\n");
	        continue;
	    }
	    j=0;
	    while(n/3)
	    {
	    	a[j]=n%3;
	    	n/=3;
	    	j++;
	    }
	    a[j]=n%3;
        for(i=j;i>=0;i--)
        {
        	printf("%d",a[i]);
        }
        printf("\n");
	}
	return 0;
}
