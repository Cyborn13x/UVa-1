#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define N 3200
#define N1 sqrt(N)
#define lim N/5

/*problem id-11889
 *
 *language-ANSI C
 *
 */

int p[N],prime[lim],last,A,C;

void Sieve()
{
      int i,j;
      prime[last++]=2;
      for(i=4;i<N;i+=2) p[i]=1;
      for(i=3;i<=N1;i+=2) if(!p[i]) for(j=i*i;j<N;j+=2*i) p[j]=1;
      for(i=3;i<N;i+=2) if(!p[i]) prime[last++]=i;
      return;
}

int power(int b,int p)
{
      int i,ret=1;
      for(i=0;i<p;i++) ret*=b;
      return ret;
}

void Factorize(int a,int b)
{
      int i,res=1,c1,c2;
      for(i=0;i<last;i++)
      {
            c1=c2=0;
            while(a%prime[i]==0) a/=prime[i], c1++;
            while(b%prime[i]==0) b/=prime[i], c2++;
            if(c2>c1) res*=power(prime[i],c2);
      }
      if(b!=1 && a==1) res*=b;
      printf("%d\n",res);
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	Sieve();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&A,&C);
		if(C%A) printf("NO SOLUTION\n");
		else Factorize(A,C);
	}
	return 0;
}
