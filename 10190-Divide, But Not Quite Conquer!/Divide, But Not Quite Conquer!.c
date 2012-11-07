#include <stdio.h>

/*problem id-10190
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,blank,test=0,a[500];
	while(scanf("%d %d",&n,&m)!=EOF)
	{
	      a[x=0]=n, y=1;
	      if(m<2 || n<2 || m>n) { printf("Boring!\n"); continue; }
		while(y && n%m==0)
		{
		      n/=m;
			a[++x]=n;
			if(a[x]==1) y=0;
		}
		if(a[x]!=1) printf("Boring!\n");
		else
		{
		      printf("%d",a[0]);
		      for(i=1;i<=x;i++) printf(" %d",a[i]);
		      printf("\n");
		}
	}
	return 0;
}
