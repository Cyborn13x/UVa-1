#include <stdio.h>

/*problem id-10656
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,test,blank;
	while(scanf("%d",&n) && n)
	{
		for(i=y=t=0;i<n;i++)
		{
			scanf("%d",&x);
			if(x)
			{
			      if(y) putchar(' ');
			      printf("%d",x);
			      y=1;
                  }
		}
		if(!y) printf("0");
		putchar('\n');
	}
	return 0;
}
