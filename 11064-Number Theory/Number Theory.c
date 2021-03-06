#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define N 46350
#define N1 sqrt(N)
#define lim N/3

/*problem id-11064
 *
 *language-ANSI C
 *
 */

int p[N];
int prime[lim];
int last;

void Sieve()
{
      register int i;
      register int j;
      register int k=1;
      prime[0]=2;
      for(i=4;i<N;i+=2) p[i]=1;
      for(i=3;i<=N1;i+=2) if(!p[i]) for(j=i*i;j<N;j+=2*i) p[j]=1;
      for(i=3;i<N;i+=2) if(!p[i]) prime[k++]=i;
      last=k;
      return;
}

int EulerPhi(int n)
{
      int i;
      int ret=n;
      int powr;
      int m=n;
      int divi=1;
      if(n==1) return 0;
      for(i=0;i<last && prime[i]*prime[i]<=n;i++)
      {
      	if(n%prime[i]==0)
      	{
      	      powr=0;
      	      while(n%prime[i]==0) { powr++; n/=prime[i]; }
      	      divi*=(powr+1);
      	      ret/=prime[i];
      	      ret*=(prime[i]-1);
      	}
      }
      if(n!=1)
      {
            divi*=2;
            ret/=n;
            ret*=(n-1);
      }divi--;
      return m-ret-divi;
}

int main()
{
	int n;
	Sieve();
      while(scanf("%d",&n)!=EOF) printf("%d\n",EulerPhi(n));
	return 0;
}
