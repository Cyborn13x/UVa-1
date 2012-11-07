#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


/*686
 *
 *
 *
 */
bool primes[1000000];

int main()
{
	int i;
	int j;
	int n;
	int c;
	for(i=2;i<1000000;i++)
	{
	      if(primes[i]==0)
            {
                  for(j=2*i;j<1000000;j+=i)
                  {
                        primes[j]=1;
                  }
            }
	}
	while(scanf("%d",&n)==1 && n)
	{
	      c=0;
	      for(i=2;i<=n/2;i++)
	      {
	      	if(!primes[i] && !primes[n-i])
	      	{
	      	      c++;
	      	}
	      }
	      printf("%d\n",c);
	}
	return 0;
}
