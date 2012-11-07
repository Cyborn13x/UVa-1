#include <stdio.h>

/*problem id-10910
 *
 *language-ANSI C
 *
 */

typedef unsigned long long int ull;

int min(int a,int b) { return a<b ? a : b; }

void nCr(int n,int r)
{
      ull ret=1;
      int i;
      for(i=1;i<=r;i++) ret=ret*(n-i+1)/i;
      printf("%llu\n",ret);
      return;
}

int main()
{
	int n,t,p,x,y,test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d %d",&n,&t,&p);
		x=n+(y=t-n*p)-1;
		if(y<0) printf("0\n");
		else nCr(x,min(y,x-y));
	}
	return 0;
}
