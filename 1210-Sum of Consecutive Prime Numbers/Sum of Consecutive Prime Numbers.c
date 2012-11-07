#include <stdio.h>
#include <math.h>

#define N 10025
#define N1 sqrt(N)
#define lim N/4

/*problem id-1210
 *
 *language-ANSI C
 *
 */

int p[N],prime[lim],last=1,data[10005],mem[lim];

void Sieve()
{
      int i,j;
      prime[last++]=2;
      for(i=4;i<N;i+=2) p[i]=1;
      for(i=3;i<=N1;i+=2) if(!p[i]) for(j=i*i;j<N;j+=2*i) p[j]=1;
      for(i=3;i<N;i+=2) if(!p[i]) prime[last++]=i;
      return;
}

void PreCal()
{
      int i,j,t;
      Sieve();
	for(i=1;i<last;i++) mem[i]=mem[i-1]+prime[i];
	for(i=1;i<last;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			t=mem[i]-mem[j];
			if(t>10000) break;
			data[t]++;
		}
	}
	return;
}

int main()
{
	int n;
	PreCal();
	while(scanf("%d",&n) && n) printf("%d\n",data[n]);
	return 0;
}
