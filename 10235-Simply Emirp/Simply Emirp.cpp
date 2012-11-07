#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

bool p(int n)
{
      if(n<=2) return 0;
      for(int i=2;i<=n/2;i++)
      {
      	if(!(n%i)) return 0;
      }
      return 1;
}

int r(int n)
{
      int x=0;
      int m=10;
      while(n)
      {
            x*=m;
      	x+=n%10;
      	n/=10;
      }
      return x;
}
int main()
{
	int n;
	int fn;
	while(scanf("%d",&n)!=EOF)
	{
	      fn=r(n);
		if(p(fn) && p(n) && fn!=n) printf("%d is emirp.\n",n);
		else if(p(n)) printf("%d is prime.\n",n);
            else printf("%d is not prime.\n",n);
	}
	return 0;
}
