#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-11689
 *
 *language-ANSI C
 *
 */

int main()
{
	int i;
	int s;
	int n;
	int k;
	int have;
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d %d %d",&n,&s,&k);
	    n+=s;
	    have=0;
	    while(n/k)
	    {
	    	have+=(n/k);
	    	n=n%k+(n/k);
	    }
          printf("%d\n",have);
	}
	return 0;
}

