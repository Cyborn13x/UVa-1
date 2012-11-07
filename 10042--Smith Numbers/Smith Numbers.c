#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define N 32000
#define N1 sqrt(N)
#define lim N/4

/*problem id-10042
 *
 *language-ANSI C
 *
 */

int p[N];
int prime[lim];
int last;

void Sieve()
{
      int i,j,k=1;
      prime[0]=2;
      for(i=4;i<N;i+=2) p[i]=1;
      for(i=3;i<=N1;i+=2) if(!p[i]) for(j=i*i;j<N;j+=2*i) p[j]=1;
      for(i=3;i<N;i+=2) if(!p[i]) prime[k++]=i;
      last=k;
      return;
}

int SumOfDigits(int n)
{
      int c=0;
      while(n) { c+=n%10; n/=10; }
      return c;
}

int IsPrime(int n)
{
      int i;
      if(n<N) return !p[n];
      if(n%2==0) return 0;
      for(i=0;i<last;i++) if(n%prime[i]==0) return 0;
      return 1;
}

int SumOfFactors(int n)
{
      int i,k,m;
      int tmp=n;
      int sum=0;
      if(IsPrime(n)) return -1;
      for(i=0;prime[i]*prime[i]<=n && i<last;i++)
      {
            if(n%prime[i]==0)
            {
                  m=0;
                  while(n%prime[i]==0)
                  {
                        m++;
                        n/=prime[i];
                  }
                  sum+=(m*SumOfDigits(prime[i]));
            }
      }
      if(tmp==n) return -1;
      if(n!=1) sum+=SumOfDigits(n);
      return sum;
}

int main()
{
	int i,n,t;
	Sieve();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=n+1;;i++) if(SumOfDigits(i)==SumOfFactors(i)) break;
		printf("%d\n",i);
	}
	return 0;
}
