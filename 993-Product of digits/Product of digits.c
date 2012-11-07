#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

/*problem id-993
 *
 *language-ANSI C
 *
 */

int cmp(const void *a,const void *b)
{
      return *(int *)a-*(int *)b;
}

int main()
{
	int i,j,k,l,m,n,t,x,y,blank,test=0,a[20];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n<=1) { printf("%d\n",n); continue; }
		for(m=9,x=0;m>1;m--)
		{
			while(n%m==0)
			{
				n/=m;
				a[x++]=m;
			}
		}
		if(n!=1) printf("-1\n");
		else
		{
		      qsort(a,x,sizeof(int),&cmp);
		      for(i=0;i<x;i++) printf("%d",a[i]);
		      printf("\n");
		}
	}
	return 0;
}
