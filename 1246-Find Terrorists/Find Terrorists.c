#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*problem id-1246
 *
 *language-ANSI C
 *
 */

int p[110];
int prime[50];
int last;

int factor(int n)
{
      int k=0;
      int c=1;
      int i;
      for(i=0;prime[i]*prime[i]<=n && i<last;i++)
      {
            if(n%prime[i]==0)
            {
                  k=0;
                  while(n%prime[i]==0)
                  {
                        k++;
                        n/=prime[i];
                  }
                  c*=(k+1);
            }
      }
      if(n>1) c*=2;
      return c;
}

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;
	int t;
	int x;
	int y;
	int ans[10002];
	for(i=4,p[0]=p[1]=1;i<=100;i+=2) p[i]=1;
	for(i=3;i<=10;i+=2) if(!p[i]) for(j=i*i;j<=100;j+=2*i) p[j]=1;
	for(i=3,last=0,prime[last++]=2;i<=100;i+=2) if(!p[i]) prime[last++]=i;
	for(i=1;i<=10000;i++) ans[i]=factor(i);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&x,&y);
		for(i=x,k=0;i<=y;i++) if(!p[ans[i]]) {k=1;printf("%d",i);break;}
		for(i=i+1;i<=y;i++) if(!p[ans[i]]) printf(" %d",i);
		if(!k) printf("-1");
		printf("\n");
	}
	return 0;
}
