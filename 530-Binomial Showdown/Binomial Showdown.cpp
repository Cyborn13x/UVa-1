#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-530
 *
 *language-C++
 *
 */

int main()
{
	int i;
	int j;
	int N;
	int M;
	int m;
	int n;
      long long unsigned int c;
	while(scanf("%d %d",&N,&M)==2 && (N || M))
	{
            c=1;
		if(M>N/2)
		{
		      M=N-M;
		}
		for(i=1;i<=M;i++)
		{
			c*=(N-M+i);
			c/=i;
		}
            printf("%llu\n",c);
	}
	return 0;
}
