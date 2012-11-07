#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int check(int n)
{
    int sum=0;
    for(int i=1;i<=n/2;i++)
    {
    	if(n%i==0)
    	{
    	    sum+=i;
    	}
    }
    if(sum==n)
    {
        return 0;
    }
    else if(sum>n)
    {
        return 1;
    }
    return -1;
}

int main()
{
	int numbers[100],n,i,j;
	for(i=0;;i++)
	{
		scanf("%d",&n);
		if(!n)
		{
		    break;
		}
		numbers[i]=n;
	}
	printf("PERFECTION OUTPUT\n");
	for(j=0;j<i;j++)
	{
		if(check(numbers[j])==0)
		{
		    printf("%5d  PERFECT\n",numbers[j]);
		}
		else if(check(numbers[j])==1)
		{
		    printf("%5d  ABUNDANT\n",numbers[j]);
		}
		else
		{
		    printf("%5d  DEFICIENT\n",numbers[j]);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
