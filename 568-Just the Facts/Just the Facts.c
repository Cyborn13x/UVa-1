#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*problem id-568
 *
 *language-ANSI C
 *
 *
 */

int LastDigit(int n)
{
      int i;
      int j;
      int a;
      int a2=0;
      int a5=0;
      int ans=1;
      for(i=1;i<=n;i++)
      {
      	j=i;
      	while(j%2==0)
      	{
      		j/=2;
      		a2++;
      	}
      	while(j%5==0)
      	{
      		j/=5;
      		a5++;
      	}
      	ans=(ans*(j%10))%10;
      }
      a=a2-a5;
      for(i=0;i<a;i++)
      {
      	ans=(ans*2)%10;
      }
      return ans;
}

int main()
{
	int i;
	int j;
	int n;
	while(scanf("%d",&n)==1)
	{
		printf("%5d -> %d\n",n,LastDigit(n));
	}
	return 0;
}
