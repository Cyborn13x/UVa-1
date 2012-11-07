#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-10170
 *
 *language-ANSI C
 *
 *
 */
int main()
{
	unsigned long long int i;
	unsigned long long int j;
	unsigned long long int n;
	unsigned long long int x;
	unsigned long long int s;
	while(scanf("%llu %llu",&n,&x)==2)
	{
	      s=0;
		for(i=n;s<x;i++)
		{
		      s+=i;
		}
		printf("%llu\n",i-1);
	}
	return 0;
}
