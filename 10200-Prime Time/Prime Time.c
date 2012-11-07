#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define N 10010
#define N1 sqrt(N)
#define lim N/5

/*problem id-10200
 *
 *language-ANSI C
 *
 */

int last;
int p[N];
int prime[lim];
int data[N];
int dp[N];

void sieve()
{
      register int i;
      register int j;
      register int k=1;
      p[0]=p[1]=1; prime[0]=2;
      for(i=4;i<N;i+=2) p[i]=1;
      for(i=3;i<N1;i+=2) if(!p[i]) for(j=i*i;j<N;j+=2*i) p[j]=1;
      for(i=3;i<N;i+=2) if(!p[i]) prime[k++]=i;
      last=k;
      return;
}

int IsPrime(int n)
{
      register int i;
      if(n<N) return !p[n];
      for(i=0;i<last;i++) if(n%prime[i]==0) return 0;
      return 1;
}

void Database()
{
      register int i;
      int k=0;
      sieve();
      for(i=0;i<N;i++) if(IsPrime(i*i+i+41)) data[i]=1;
      for(i=0;i<N;i++) { if(data[i]) k++; dp[i]=k; }
      return;
}

int main()
{
	int i;
	int m;
	int n;
      double ans;
      Database();
      while(scanf("%d %d",&m,&n)!=EOF)
      {
      	ans=((dp[n]-dp[m-1])*1.0)/(n-m+1);
      	printf("%.2lf\n",ans*100.0+1e-9);
      }
	return 0;
}
