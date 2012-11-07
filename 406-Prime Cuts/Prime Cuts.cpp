#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define N 1005

/*problem id-406
 *
 *language-C++
 *
 */

bool primes[N];
int t[175];

void seive()
{
      int i;
      int j;
      for(i=2;i<N;i++)
	{
	      if(primes[i]==0)
            {
                  for(j=2*i;j<N;j+=i)
                  {
                        primes[j]=1;
                  }
            }
	}
	return;
}

int main()
{
	int i;
	int j;
	int n;
	int c=0;
	int d;
	int cnt;
	int start;
	int end;
	int mid;
	seive();
	for(i=1;i<N;i++)
	{
		if(!primes[i])
		{
		      c++;
		      t[c]=i;
		      //printf("%d th prime is %d\n",c,t[c]);
		}
	}
	while(scanf("%d %d",&n,&c)==2)
	{
	      d=0;
	      start=0;
	      end=0;
	      if(n==1 && c==1)
	      {
	            printf("1 1: 1\n\n");
	            continue;
	      }
            for(i=1;i<=n;i++)
            {
            	if(!primes[i]) d++;
            }
            printf("%d %d:",n,c);
            if(d%2==0)
            {
                  cnt=d/2;
                  start = (cnt-c+1)>=1 ? (cnt-c+1):1;
                  end = (cnt+c)<=d ? (cnt+c):d;
                  for(i=start;i<=end;i++)
                  {
                  	printf(" %d",t[i]);
                  }
            }
            else
            {
                  cnt=(d/2)+1;
                  start = (cnt-c+1)>=1 ? (cnt-c+1):1;
                  end = (cnt+c-1)<=d ? (cnt+c-1):d;
                  for(i=start;i<=end;i++)
                  {
                  	printf(" %d",t[i]);
                  }
            }
            printf("\n\n");
	}
	return 0;
}
