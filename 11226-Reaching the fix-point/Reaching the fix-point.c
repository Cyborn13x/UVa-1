#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-11226
 *
 *language-ANSI C
 *
 */

#define N 500002
#define N1 sqrt(N)
#define lim N/4

int last,p[N],prime[lim],sopf[N],lsopf[N];

void Sieve()
{
      int i,j;
      prime[0]=2, last=1;
      for(i=4;i<N;i+=2) p[i]=1;
      for(i=3;i<=N1;i+=2) if(!p[i]) for(j=i*i;j<N;j+=2*i) p[j]=1;
      for(i=3;i<N;i+=2) if(!p[i]) prime[last++]=i;
      return;
}

int sum(int n)
{
      int i,ret=0;
      if(!p[n]) return n;
      for(i=0;prime[i]*prime[i]<=n && i<last;i++)
      {
            while(n%prime[i]==0)
            {
                  ret+=prime[i];
                  n/=prime[i];
            }
      }
      if(n!=1) ret+=n;
      return ret;
}

int Depth(int n)
{
      if(lsopf[n]) return lsopf[n];
      if(n==sopf[n]) return 1;
      return lsopf[n]=1+Depth(sopf[n]);
}

void PreCal()
{
      int i;
      Sieve();
      for(i=2;i<N;i++) sopf[i]=sum(i);
      for(i=2;i<N;i++) lsopf[i]=Depth(i);
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,test=0,blank;
	PreCal();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&m,&n); k=0;
		if(m>n) { l=m, m=n, n=l; }
		for(i=m;i<=n;i++)if(lsopf[i]>k) k=lsopf[i];
		printf("Case #%d:\n%d\n",++test,k);
	}
	return 0;
}
