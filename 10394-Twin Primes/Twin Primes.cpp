#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problen id-10394
 *
 *language-C++
 *
 *
 */


bool prime[20000000];
int in[100005];

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m=0;
	int n;
	for(i=2;i<20000000;i++)
	{
	      if(prime[i]==0)
		{
		      for(j=2*i;j<20000000;j+=i)
                  {
                        prime[j]=1;
                  }
		}
	}
	for(i=5;i<18445500;i++)
	{
		if(!prime[i] && !prime[i-2])
		{
		      in[m++]=i;
		}
	}
	while(scanf("%d",&n)==1)
	{
		printf("(%d, %d)\n",in[n-1]-2,in[n-1]);
	}
	return 0;
}
