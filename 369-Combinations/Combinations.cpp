#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


/*problem id-369
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
	int n;
	int m;
	long long unsigned int c;
	while(scanf("%d %d",&N,&M)==2)
	{
		if(!N && !M)
		{
		      break;
		}
		c=1;
		n=N-M+1;
		m=1;
		while(n<=N || m<=M)
		{
                  if(n<=N)
                  {
                        c*=n;
                        n++;
                  }
                  if(m<=M)
                  {
                        c/=m;
                        m++;
                  }
            }
            printf("%d things taken %d at a time is %llu exactly.\n",N,M,c);
	}
	return 0;
}
