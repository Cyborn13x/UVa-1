#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define N 32800
#define N1 sqrt(N)
#define lim N/4

/*problem id-516
 *
 *language-ANSI C
 *
 */

int last,p[N],prime[lim],a1[500],a2[500];

void Sieve()
{
      int i,j;
      prime[0]=2, last=1;
      for(i=4;i<N;i+=2) p[i]=1;
      for(i=3;i<=N1;i+=2) if(!p[i]) for(j=i*i;j<N;j+=2*i) p[j]=1;
      for(i=3;i<N;i+=2) if(!p[i]) prime[last++]=i;
      return;
}

void Factorize(int n)
{
      int i,c,flag=0,cnt=0;
      if(!p[n]) { printf("%d 1\n",n); return; }
      for(i=0;prime[i]*prime[i]<=n && i<last;i++)
      {
      	if(n%prime[i]==0)
      	{
      	      c=0;
      	      while(n%prime[i]==0)
      	      {
      	      	c++;
      	      	n/=prime[i];
      	      }
      	      a1[cnt]=prime[i];
      	      a2[cnt++]=c;
      	}
      }
      if(n!=1) a1[cnt]=n, a2[cnt++]=1;
      --cnt;
      printf("%d %d",a1[cnt],a2[cnt]);
      for(--cnt;cnt>=0;cnt--) printf(" %d %d",a1[cnt],a2[cnt]);
      putchar('\n');
      return;
}

int main()
{
	int i,j,k,l,m,n,num,t,x,y,test,blank;
	char *p,a[500];
	Sieve();
	while(gets(a) && strcmp(a,"0"))
	{
		num=1;
		p=strtok(a," ");
		while(p!=NULL)
		{
			x=atoi(p);
			p=strtok(NULL," ");
			y=atoi(p);
			num*=pow(x,y);
			p=strtok(NULL," ");
		}
		num--;
		Factorize(num);
	}
	return 0;
}
