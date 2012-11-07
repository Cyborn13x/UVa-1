#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int n,i,m,rem,d[10],TestCase;
	scanf("%d",&TestCase);
	for(int j=0;j<TestCase;j++)
	{
		scanf("%d",&n);
		for(i=0;i<10;i++)
		{
			d[i]=0;
		}
		for(i=1;i<=n;i++)
		{
		    m=i;
		    while((m/10)!=0)
		    {
		        rem=m%10;
		        d[rem]++;
		    	m=m/10;
		    }
		    d[m]++;
		}
		for(i=0;i<10;i++)
		{
			if(i<10-1)
			{
			    printf("%d ",d[i]);
			}
			else
			{
			    printf("%d",d[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
