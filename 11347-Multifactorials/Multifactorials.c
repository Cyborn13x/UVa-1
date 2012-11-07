#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX 1000000000000000000
#define N 1002
#define N1 sqrt(N)
#define lim N/5

/*problem id-11347
 *
 *language-ANSI C
 *
 */

typedef unsigned long long int ull;

int p[N],prime[lim],num[N],last,k;

void Sieve()
{
      int i,j;
      prime[last++]=2;
      for(i=4;i<N;i+=2) p[i]=1;
      for(i=3;i<=N1;i+=2) if(!p[i]) for(j=i*i;j<N;j+=2*i) p[j]=1;
      for(i=3;i<N;i+=2) if(!p[i]) prime[last++]=i;
      return;
}

ull Factorize(int n)
{
      int i,j,cnt;
      ull ret=1;
      for(i=0;i<last && prime[i]<=n;i++)
      {
      	for(j=n,cnt=0;j>0;j-=k)
      	{
      		while(num[j]%prime[i]==0)
      		{
      			num[j]/=prime[i], cnt++;
      		}
            }
            if(cnt) ret*=(ull)(cnt+1);
            if(ret>MAX) return MAX+5;
      }
      return ret;
}

int main()
{
	int i,j,l,m,n,t,x,y,blank=0,test=0;
	ull ans;
	char a[100],*p;
      Sieve();
      scanf("%d",&t);
      while(t--)
      {
      	scanf("%s",a);
      	for(i=strlen(a)-1,k=0;a[i]=='!';i--) k++;
      	p=strtok(a,"!");
      	n=atoi(p);
      	for(i=1;i<=n;i++) num[i]=i;
      	printf("Case %d: ",++test);
      	if((ans=Factorize(n))>MAX) printf("Infinity\n");
      	else printf("%llu\n",ans);
      }
	return 0;
}
