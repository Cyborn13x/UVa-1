#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define N 46500
#define N1 sqrt(N)
#define lim N/5

/*problem id-10622
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

int gcd(int a,int b) { return b ? gcd(b,a%b) : a; }

int negative(int n)
{
      int i;
      for(i=n-1;i>0;i--) if(i&1 && !(n%i)) return i;
}

int Factorize(int n)
{
      int i,j=0,ret,cnt;
      for(i=0;i<last && prime[i]*prime[i]<=n;i++)
      {
            if(n%prime[i]==0)
            {
                  cnt=0;
                  while(n%prime[i]==0)
                  {
                        n/=prime[i], cnt++;
                  }
                  if(!j) ret=cnt;
                  else ret=gcd(ret,cnt);
                  j=1;
            }
      }
      if(n!=1) ret=1;
      return ret;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
      Sieve();
      while(scanf("%d",&n) && n)
      {
            if(n==-2147483648) x=31;
      	else if(n<0) x=Factorize(-n);
      	else x=Factorize(n);
      	if(n<0 && !(x&1)) x=negative(x);
      	printf("%d\n",x);
      }
	return 0;
}
