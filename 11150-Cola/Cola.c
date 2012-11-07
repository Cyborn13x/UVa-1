#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
	int i;
	int s;
	int n;
	while(scanf("%d",&n)==1)
	{
	      s=0;
		if(!(n%2))
		{
		      s=3+((n/2)-1)*3;
		}
		else
		{
		      s=1+(((n+1)/2)-1)*3;
		}
		printf("%d\n",s);
	}
	return 0;
}
