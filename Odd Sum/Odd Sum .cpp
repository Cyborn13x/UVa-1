#include<stdio.h>

int main()
{
	int test_case,a,b,sum;
	scanf("%d",&test_case);
	for(int i=1;i<=test_case;i++)
	{
	      sum=0;
		scanf("%d",&a);
		scanf("%d",&b);
		for(int j=a;j<=b;j++)
		{
			if(j%2==1)
			{
			      sum+=j;
			}
		}
		printf("Case %d: %d\n",i,sum);
	}
	return 0;
}
