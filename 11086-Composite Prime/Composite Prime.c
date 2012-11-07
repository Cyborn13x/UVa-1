#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define N 1048600
#define N1 sqrt(N)
#define N2 N/2
#define lim N/3

/*problem id-11086
 *
 *language-ANSI C
 *
 */

int p[N];

void Sieve()
{
      int i,j;
      for(i=4;i<N;i+=2) p[i]=1;
      for(i=3;i<=N1;i+=2) if(!p[i]) for(j=i*i;j<N;j+=2*i) p[j]=1;
      for(i=4;i<=N2;i++) if(p[i]) for(j=2*i;j<N;j+=i) p[j]=0;
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank;
	Sieve();
      while(scanf("%d",&n)!=EOF)
      {
      	for(i=x=0;i<n;i++)
      	{
      		scanf("%d",&y);
      		if(p[y]) x++;
      	}
      	printf("%d\n",x);
      }
	return 0;
}
