#include <stdio.h>

/*problemid-12416
 *
 *language-ANSI C
 *
 */

char a[1000005];

int main()
{
	int i,j,k,l,m,n,t,x,y,max,blank=0,test=0,sum;
	while(gets(a)!=NULL)
	{
		for(i=max=x=0;a[i];i++)
		{
			if(a[i]==' ') x++;
			else
			{
			      if(x>max) max=x;
			      x=0;
			}
		}
		sum=1, x=0;
		while(sum<max) x++, sum*=2;
		printf("%d\n",x);
	}
	return 0;
}
