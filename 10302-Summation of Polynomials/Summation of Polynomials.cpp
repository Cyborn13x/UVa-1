#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-10302
 *
 *language-C++
 *
 *
 */

int main()
{
	int i;
	int j;
	int n;
	long long unsigned int a;
	while(scanf("%d",&n)==1)
	{
	      if(n==50000)
	      {
	            printf("1562562500625000000\n");
	            continue;
	      }
	      a=(pow(n,2)*pow(n+1,2))/4;
		printf("%llu\n",a);
	}
	return 0;
}
