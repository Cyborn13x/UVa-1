#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define SIZE 64730
#define N 1002
#define N1 sqrt(N)
#define lim N/4

/*problem id-11876
 *
 *language-ANSI C
 *
 */

int p[N],prime[lim],last,nod[SIZE];

void Sieve()
{
      int i,j;
      prime[last++]=2;
      for(i=4;i<N;i+=2) p[i]=1;
      for(i=3;i<=N1;i+=2) if(!p[i]) for(j=i*i;j<N;j+=2*i) p[j]=1;
      for(i=3;i<N;i+=2) if(!p[i]) prime[last++]=i;
      return;
}

int Divisors(int n)
{
      int i,c,ret=1;
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
      	      ret*=c+1;
      	}
      }
      if(n!=1) ret*=2;
      return ret;
}

void Precal()
{
      int i;
      Sieve();
      for(i=1,nod[0]=1;i<SIZE;i++) nod[i]=nod[i-1]+Divisors(nod[i-1]);
      return;
}

int BinarySearch(int low,int high,int n)
{
      int mid;
      while(low<=high)
      {
      	mid=(low+high)/2;
      	if(n>nod[mid])
      	{
      	      low=mid+1;
      	      if(n<nod[mid+1]) return mid+1;
      	}
      	else if(n==nod[mid]) return mid;
      	else
      	{
      	      high=mid-1;
      	      if(n>nod[mid-1]) return mid;
      	}
      }
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank,ans,test=0;
	Precal();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&i,&j);
		m=BinarySearch(0,SIZE,i);
		n=BinarySearch(0,SIZE,j);
		ans=n-m+1-((j==nod[n])? 0:1);
		printf("Case %d: %d\n",++test,ans);
	}
	return 0;
}
