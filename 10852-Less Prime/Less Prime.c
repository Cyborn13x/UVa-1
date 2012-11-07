#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define Clear(x,y) memset(x,y,sizeof(x))
#define For(x,n) for(x=0;x<n;x++)
#define abs(x) ((x<0)?(-(x)):(x))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long int
#define INF 1<<30
#define SZ 100000
#define N 10002
#define N1 sqrt(N)
#define lim N/4

/*problem id-10852
 *
 *language-ANSI C
 *
 */

int p[N],prime[lim],last;

void Sieve()
{
      int i,j;
      prime[last++]=2;
      for(i=4;i<N;i+=2) p[i]=1;
      for(i=3;i<=N1;i+=2) if(!p[i]) for(j=i*i;j<N;j+=2*i) p[j]=1;
      for(i=3;i<N;i+=2) if(!p[i]) prime[last++]=i;
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0,res;
      Sieve();
      scanf("%d",&t);
      while(t--)
      {
      	scanf("%d",&n);
      	res=-INF;
      	for(i=0;prime[i]<=n && i<last;i++) if(n%prime[i]>res) res=n%prime[i], x=prime[i];
      	printf("%d\n",x);
      }
	return 0;
}
