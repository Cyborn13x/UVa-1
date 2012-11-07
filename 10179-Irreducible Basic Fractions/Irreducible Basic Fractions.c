#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define N 35000
#define N1 sqrt(N)
#define lim N/3

/*problem id-10179
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

int EulerPhi(int n)
{
      int ret=n;
      int i;
      if(n==1) return 1;
      for(i=0;i<last && prime[i]*prime[i]<=n;i++)
      {
      	if(n%prime[i]==0)
      	{
      	      while(n%prime[i]==0) n/=prime[i];
      	      ret/=prime[i];
      	      ret*=(prime[i]-1);
      	}
      }
      if(n!=1)
      {
            ret/=n;
            ret*=(n-1);
      }
      return ret;
}

int main()
{
	int n;
	int ans;
	Sieve();
	while(scanf("%d",&n) && n) printf("%d\n",EulerPhi(n));
	return 0;
}
