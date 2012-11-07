#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define N 1000011

/*problem id-10948
 *
 *language-C++
 *
 */

bool primes[N];

int main()
{
	int i;
	int j;
	int n;
	bool f;
	for(i=4;i<N;i+=2) primes[i]=1;
	for(i=3;i<N/2;i+=2) if(!primes[i]) for(j=2*i;j<N;j+=i) primes[j]=1;
	while(scanf("%d",&n)==1 && n)
	{
	    f=0;
	      for(i=2;i<=n/2;i++)
	      {
	      	if(!primes[i] && !primes[n-i])
	      	{
	      	      printf("%d:\n%d+%d\n",n,i,n-i);
	      	      f=1;
	      	      break;
	      	}
	      }
	      if(!f) printf("%d:\nNO WAY!\n",n);
	}
	return 0;
}
