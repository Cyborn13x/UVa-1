#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define N 10005
#define N1 sqrt(N)
#define lim N/3

/*problem id-10311
 *
 *language-ANSI C
 *
 */

int p[N];
int prime[lim];
int last;

void Sieve()
{
      int i;
      int j;
      int k=1;
      prime[0]=2;
      for(i=4;i<N;i+=2) p[i]=1;
      for(i=3;i<=N1;i+=2) if(!p[i]) for(j=i*i;j<N;j+=2*i) p[j]=1;
      for(i=3;i<N;i+=2) if(!p[i]) prime[k++]=i;
      last=k;
      return;
}

int IsPrime(int n)
{
      int i;
      int s=sqrt(n);
      if(n<N) return !p[n];
      for(i=0;i<last && prime[i]<=s;i++) if(n%prime[i]==0) return 0;
      return 1;
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int x;
	int y;
	int flag;
	Sieve();
	while(scanf("%d",&n)!=EOF)
	{
		if(n&1)
		{
		      if(n<=3) printf("%d is not the sum of two primes!\n",n);
		      else
		      {
		            if(IsPrime(n-2)) printf("%d is the sum of 2 and %d.\n",n,n-2);
		            else printf("%d is not the sum of two primes!\n",n);
		      }
		}
		else
		{
		      i=n>>1;
		      if(!(i&1)) i--;
		      for(flag=0;i>=3;i-=2)
		      {
		      	if(IsPrime(i) && IsPrime(n-i)&& n-i!=i)
		      	{
		      	      printf("%d is the sum of %d and %d.\n",n,i,n-i);
		      	      flag=1; break;
		      	}
		      }
		      if(!flag) printf("%d is not the sum of two primes!\n",n);
		}
	}
	return 0;
}
