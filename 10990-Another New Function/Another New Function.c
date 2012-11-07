#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

/*problem id-10990
 *
 *language-ANSI C
 *
 */

#define N 2000002
#define N1 N/2

int p[N];
int phi[N];
int depth[N];
int sodp[N];

void EulerPhiSieve()
{
      register int i;
      register int j;
      phi[2]=depth[2]=1;
      for(i=3;i<N;i++) phi[i]=i;
      for(i=4;i<N;i+=2) { phi[i]/=2;p[i]=1; }
      for(i=3;i<=N;i+=2)
      {
      	if(!p[i])
      	{
      	      phi[i]=i-1;
      	      for(j=i+i;j<N;j+=i) { phi[j]/=i; phi[j]*=(i-1); p[j]=1; }
      	}
      }
      return;
}

int DepthPhi(int n)
{
      int below;
      if(depth[n]) return depth[n];
      below=DepthPhi(phi[n]);
      depth[n]=below+1;
      return depth[n];
}

void Database()
{
      register int i;
      EulerPhiSieve();
      for(i=2;i<N;i++) depth[i]=DepthPhi(i);
      for(i=2;i<N;i++) sodp[i]=sodp[i-1]+depth[i];
      return;
}

int main()
{
      int i;
	int m;
	int n;
	int t;
      Database();
      scanf("%d",&t);
      while(t--)
      {
      	scanf("%d %d",&m,&n);
      	printf("%d\n",sodp[n]-sodp[m-1]);
      }
      return 0;
}
