#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-10140
 *
 *language-ANSI C
 *
 */


#define N 46500
#define N1 sqrt(N)
#define lim N/3

int p[N];
int prime[lim];
int last;

void Sieve()
{
      int i;
      int j;
      int k=1;
      prime[0]=2;
      for(i=4,p[0]=p[1]=1;i<N;i+=2) p[i]=1;
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
      unsigned long long int i;
	int j;
	int k;
	int m;
	int n;
	int t;
	int x;
	int y;
	int cnt;
	int close;
	int distn;
	int l;
	int cx;
	int cy;
	int dx;
	int dy;
	int L;
	int U;
	Sieve();
	while(scanf("%d %d",&L,&U)!=EOF)
	{
		for(i=(unsigned long long int )L,cnt=0,close=1<<25,distn=-1; i<=U; i++)
		{
			if(IsPrime(i))
			{
			      cnt++;k=(int )i;
			      if(cnt>1)
			      {
			            if((k-l)<close) { close=k-l; cx=l; cy=k; }
			            if((k-l)>distn) { distn=k-l; dx=l; dy=k; }
			      }
			      l=k;
			}
		}
		if(cnt<=1) printf("There are no adjacent primes.\n");
		else printf("%d,%d are closest, %d,%d are most distant.\n",cx,cy,dx,dy);
	}
	return 0;
}
