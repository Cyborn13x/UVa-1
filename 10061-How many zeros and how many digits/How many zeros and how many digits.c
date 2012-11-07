#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define SIZE 1048580
#define N 1000
#define N1 sqrt(N)
#define lim N/4

/*problem id-10061
 *
 *language-ANSI C
 *
 */

int last,p[N],prime[lim],factor[250],cnt;
double lg[SIZE];

void Sieve()
{
      int i,j;
      prime[last++]=2;
      for(i=4;i<N;i+=2) p[i]=1;
      for(i=3;i<=N1;i+=2) if(!p[i]) for(j=i*i;j<N;j+=2*i) p[j]=1;
      for(i=3;i<N;i+=2) if(!p[i]) prime[last++]=i;
      return;
}

int FactorialPow(int f,int p)
{
      int ret=0;
      while(f)
      {
      	ret+=f/p;
      	f/=p;
      }
      return ret;
}

void Factorize(int n)
{
      int i,c;
      cnt=0;
      for(i=0;i<last && prime[i]*prime[i]<=n;i++)
      {
      	if(n%prime[i]==0)
      	{
      	      c=0;
      	      while(n%prime[i]==0)
      	      {
      	      	c++;
      	      	n/=prime[i];
      	      }
      	      factor[cnt]=prime[i], factor[cnt+1]=c;
      	      cnt+=2;
      	}
      }
      if(n!=1)
      {
            factor[cnt]=n;
            factor[cnt+1]=0;
            c=n;
            while(n!=1)
            {
            	factor[cnt+1]++;
            	n/=c;
            }
            cnt+=2;
      }
      return;
}

void preCal()
{
      int i;
      Sieve();
      for(i=2,lg[1]=log10(1);i<SIZE;i++) lg[i]=lg[i-1]+log10(i);
      return;
}

int main()
{
	int i,j,k,l,m,n,b,t,x,y,blank,digit,zeros,test=0;
	double ans;
	preCal();
	while(scanf("%d %d",&n,&b)!=EOF)
	{
		ans=lg[n]/log10(b)+1e-9;
		digit=ans; digit++; zeros=1000000000;
		Factorize(b);
		for(i=0;i<cnt;i+=2)
		{
			x=FactorialPow(n,factor[i])/factor[i+1];
			if(x<zeros) zeros=x;
		}
		printf("%d %d\n",zeros,digit);
	}
	return 0;
}
