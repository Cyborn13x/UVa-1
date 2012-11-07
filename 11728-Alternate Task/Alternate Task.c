#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-11728
 *
 *language-ANSI C
 *
 */

#define N 1005

int divi[N];

void Sieve()
{
      int i,j;
      for(i=1;i<1001;i++) for(j=i;j<N;j+=i) divi[j]+=i;
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank,test=0;
	Sieve();
	while(scanf("%d",&n) && n)
	{
	      printf("Case %d: ",++test);
		for(i=1000;i>=0;i--) if(n==divi[i]) { printf("%d\n",i); break; }
		if(i==-1) printf("-1\n");
	}
	return 0;
}
