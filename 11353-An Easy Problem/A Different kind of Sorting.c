#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define N 2000001
#define N1 sqrt(N)
#define lim N/4

/*problem id-11353
 *
 *language-ANSI C
 *
 */

typedef struct
{
      int num,fac;
}node;

int factor[N];
node list[N];

void SieveFactor()
{
      int i,j,k;
      for(i=2,factor[1]=1;i<N;i++)
      {
      	if(!factor[i]) factor[i]=1;
      	for(j=2;(k=i*j)<N && j<=i;j++) if(factor[j]==1) factor[k]=factor[i]+1;
      }
      return;
}

int p[N],prime[lim],last;

void Sieve()
{
      int i,j;
      prime[last++]=1, prime[last++]=2;
      for(i=4;i<N;i+=2) p[i]=1;
      for(i=3;i<=N1;i+=2) if(!p[i]) for(j=i*i;j<N;j+=2*i) p[j]=1;
      for(i=3;i<N;i+=2) if(!p[i]) prime[last++]=i;
      return;
}

int cmp(const void *p1,const void *p2)
{
      node *a=(node*)p1,*b=(node*)p2;
      if(a->fac!=b->fac) return a->fac - b->fac;
      return a->num - b->num;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0;
	Sieve();
	SieveFactor();
	for(i=4,x=0;i<N;i++) if(p[i]) list[x].num=i, list[x++].fac=factor[i];
	qsort(list,x,sizeof(node),&cmp);
	while(scanf("%d",&n) && n)
	{
	      printf("Case %d: ",++test);
		if(n<148935) printf("%d\n",prime[n-1]);
		else { n-=148935; printf("%d\n",list[n].num); }
	}
	return 0;
}
