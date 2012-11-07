#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-294
 *
 *language-C++
 *
 */

bool p[1000000];
int prime[100000];

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int u;
	int c;
	int count;
	int maxn;
	int maxd;
	int temp;
	int s;
	k=1;
	prime[0]=2;
	for(i=4;i<500002;i+=2) p[i]=1;
	for(i=3;i<500002;i+=2) if(!p[i]) {prime[k++]=i;for(j=2*i;j<1000000;j+=i) p[j]=1;}
	m=k-1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&l,&u);
		maxd=0;
		for(j=l;j<=u;j++)
		{
		      count=1;
		      temp=j;
		      for(i=0;prime[i]<temp && i<m;i++)
                  {
                        if(temp%prime[i]==0)
                        {
                              c=0;
                              while(temp%prime[i]==0)
                              {
                                    temp/=prime[i];
                                    c++;
                              }
                              count*=c+1;
                        }
                  }
                  if(temp>1) count*=2;
                  if(count>maxd)
                  {
                        maxd=count;
                        maxn=j;
                  }
		}
            printf("Between %d and %d, %d has a maximum of %d divisors.\n",l,u,maxn,maxd);
	}
	return 0;
}
