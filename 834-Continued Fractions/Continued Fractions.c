#include <stdio.h>

/*problem id-834
 *
 *language-ANSI C
 *
 */

int main()
{
	int m;
	int n;
	int t;
      while(scanf("%d %d",&m,&n)!=EOF)
      {
      	printf("[%d;",m/n);
      	m-=(m/n)*n;
      	while(m!=1)
      	{
      		t=m, m=n, n=t;
      		printf("%d,",m/n); m-=(m/n)*n;
      	}
      	printf("%d]\n",n);
      }
	return 0;
}
