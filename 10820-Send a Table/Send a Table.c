#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define N 50005
#define N1 N/2

/*problem id-10820
 *
 *language-ANSI C
 *
 */

int p[N];
int phi[N];
int data[N];

void EulerPhiSieve()
{
      register int i;
      register int j;
      data[1]=phi[1]=phi[2]=1;
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

void Database()
{
      int i;
      EulerPhiSieve();
      for(i=2;i<N;i++) data[i]=data[i-1]+2*phi[i];
      return;
}

int main()
{
	int n;
	Database();
	while(scanf("%d",&n) && n) printf("%d\n",data[n]);
	return 0;
}
