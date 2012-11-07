#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define INF 1<<30
#define SZ 5000002
#define N 5000002
#define N1 N/2

/*problem id-11408
 *
 *language-ANSI C
 *
 */

int p[N],last,Factor[SZ],Data[SZ];

void Sieve()
{
      int i,j,k=0;
      for(i=2;i<SZ;i++)
      {
      	if(!p[i])
      	{
      	      Factor[i]+=i;
      	      for(j=i<<1;j<N;j+=i) p[j]=1, Factor[j]+=i;
      	}
      	if(!p[Factor[i]]) k++;
      	Data[i]=k;
      }
      return;
}

int main()
{
	int x,y;
      Sieve();
      while(scanf("%d %d",&x,&y) && x) printf("%d\n",Data[y]-Data[x-1]);
	return 0;
}
