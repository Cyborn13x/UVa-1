#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*problem id-524
 *
 *language-ANSI C
 *
 */

int prime[100]={1,1};
int ring[20];
int used[20];
int N;

int IsValid(int n,int idx)
{
      if(idx==N-1)
      {
            if(!prime[ring[idx-1]+n] && !prime[n+1]) return 1;
            return 0;
      }
      return !prime[ring[idx-1]+n];
}

void PrimeRing(int n)
{
      int i;
      if(n==N)
      {
            printf("1");
            for(i=1;i<N;i++) printf(" %d",ring[i]);
            printf("\n");
            return;
      }
      for(i=2;i<=N;i++)
      {
            if(!used[i] && IsValid(i,n))
            {
                  used[i]=1;
                  ring[n]=i;
                  PrimeRing(n+1);
                  used[i]=0;
            }
      }
      return;
}

int main()
{
      int i;
      int j;
      int blank=0;
      int test=1; ring[0]=1;
	for(i=2;i<11;i++) if(!prime[i]) for(j=i*i;j<100;j+=i) prime[j]=1;
	while(scanf("%d",&N)!=EOF)
	{
	      if(blank) printf("\n");
	      printf("Case %d:\n",test++);
	      for(i=0;i<20;i++) used[i]=0;
            PrimeRing(1);
		blank=1;
	}
	return 0;
}
