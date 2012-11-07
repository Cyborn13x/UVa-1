#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define N 46350
#define N1 sqrt(N)
#define lim N/4

/*problem id-10484
 *
 *language-ANSI C
 *
 */

typedef unsigned long long ull;

int last,cnt,p[N],prime[lim],factor[500],facpo[150];

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
      	      factor[cnt++]=prime[i];
                  factor[cnt++]=c;
      	}
      }
      if(n!=1)
      {
            factor[cnt++]=n;
            factor[cnt++]=1;
      }
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank,test=0,num,div,flag;
	ull ans;
      Sieve();
      while(scanf("%d %d",&num,&div) && (num || div))
      {
            if(div<0) div=-div;
            cnt=0, ans=flag=1;
            memset(facpo,0,150*sizeof(int));
      	Factorize(div);
      	for(i=0;prime[i]<=num;i++) facpo[prime[i]]=FactorialPow(num,prime[i]);
      	for(i=0;i<cnt;i+=2)
      	{
      	      x=FactorialPow(num,factor[i]);
      	      if(x<=0) flag=0;
      	      y=x-factor[i+1]+1;
      	      if(y>=0) ans*=y;
      	      else flag=0;
      		if(ans<=0) flag=0;
      		if(x>0) facpo[factor[i]]=0;
      	}
      	for(i=0;prime[i]<=num;i++) if(facpo[prime[i]]) ans*=(facpo[prime[i]]+1);
      	if(flag) printf("%llu\n",ans);
      	else printf("0\n");
      }
	return 0;
}
