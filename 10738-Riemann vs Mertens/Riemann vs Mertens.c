#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define SZ 1000001
#define N 1002
#define N1 sqrt(N)
#define lim 170

/*problem id-10738
 *
 *language-ANSI C
 *
 */

int p[N],prime[lim],last,mu[SZ],M[SZ];

void Sieve()
{
      int i,j;
      prime[last++]=2;
      for(i=4;i<N;i+=2) p[i]=1;
      for(i=3;i<=N1;i+=2) if(!p[i]) for(j=i*i;j<N;j+=2*i) p[j]=1;
      for(i=3;i<N;i+=2) if(!p[i]) prime[last++]=i;
      return;
}

int Factorize(int n)
{
      int i,pr=0,c=0;
      for(i=0;i<last && prime[i]*prime[i]<=n;i++)
      {
      	if(n%prime[i]==0)
      	{
      	      c=0;
      	      while(n%prime[i]==0) c++, n/=prime[i];
      	      if(c>1) return 0;
      	      pr++;
      	}
      }
      if(n!=1) pr++;
      if(pr&1) return -1;
      return 1;
}

void Precal()
{
      int i;
      Sieve();
      for(i=2,mu[1]=M[1]=1;i<SZ;i++)
      {
      	mu[i]=Factorize(i);
      	M[i]+=M[i-1]+mu[i];
      }
      return;
}

int main()
{
	int n;
	Precal();
	while(scanf("%d",&n) && n) printf("%8d%8d%8d\n",n,mu[n],M[n]);
	return 0;
}
