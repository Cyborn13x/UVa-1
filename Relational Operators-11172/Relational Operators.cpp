#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int main()
{
	int i,n;
	long int Number1,Number2;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%ld %ld",&Number1,&Number2);
		if(Number1<Number2)printf("<\n");
		else if(Number1>Number2)printf(">\n");
		else printf("=\n");
	}
	return 0;
}
