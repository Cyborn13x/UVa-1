#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int main()
{
	int i;
	int j;
	long long int n;
	while(scanf("%lld",&n)==1 && n>=0)
	{
		printf("%lld",(n>1)?n*25:0);
		printf("%%\n");
	}
	return 0;
}
