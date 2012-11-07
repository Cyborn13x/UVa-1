#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int TestCase,a,b,c,sum,NumberOfSet;
	scanf("%d",&TestCase);
	for(int i=0;i<TestCase;i++)
	{
		scanf("%d",&NumberOfSet);
		sum=0;
		for(int j=0;j<NumberOfSet;j++)
		{
			scanf("%d %d %d",&a,&b,&c);
			sum+=a*c;
		}
		printf("%d\n",sum);
	}
	return 0;
}
