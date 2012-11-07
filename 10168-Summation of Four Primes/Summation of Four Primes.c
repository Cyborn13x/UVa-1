#include <stdio.h>
#include <math.h>

#define N 10000002
#define N1 sqrt(N)

/*problem id-10168
 *
 *language-ANSI C
 *
 */

int p[N],flag,a[4];

void Sieve()
{
      int i,j;
      p[0]=p[1]=1;
      for(i=4;i<N;i+=2) p[i]=1;
      for(i=3;i<=N1;i+=2) if(!p[i]) for(j=i*i;j<N;j+=2*i) p[j]=1;
      return;
}

void DFS(int n,int l)
{
      int i;
      if(l==1)
      {
            if(!p[n]) printf("%d %d %d %d\n",n,a[1],a[2],a[3]);
            flag=0;
            return;
      }
      for(i=n-2;i>=0 && flag;i--)
      {
      	if(!p[i])
      	{
      	      a[l-1]=i;
      	      DFS(n-i,l-1);
      	}
      }
      return;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank,test=0;
	Sieve();
	while(scanf("%d",&n)!=EOF)
	{
	      flag=1;
	      DFS(n,4);
	      if(flag) printf("Impossible.\n");
	}
	return 0;
}
