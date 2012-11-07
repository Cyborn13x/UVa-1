#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int c,d,TestCase;
	float n;
	scanf("%d",&TestCase);
	for(int i=0;i<TestCase;i++)
	{
		scanf("%d %d",&c,&d);
		n=5.0*d/9;
		printf("Case %d: %.2f\n",i+1,c+n);
	}
	return 0;
}
