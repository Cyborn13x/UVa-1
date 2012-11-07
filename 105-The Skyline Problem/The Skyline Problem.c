#include <stdio.h>

/*problem id-105
 *
 *language-ANSI C
 *
 */

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
	int h;
	int y;
	int space=0; k=0;
	int a[20006]={0};
	while(scanf("%d %d %d",&x,&h,&y)!=EOF) for(i=2*x;i<=2*y;i++) a[i] = h>a[i] ? h : a[i];
	for(i=0;i<=20000;i++)
	{
		if(a[i]!=k)
		{
		      if(a[i]<k)
		      {
		            if(!a[i]) printf(" %d 0",(i-1)/2);
		            else printf(" %d %d",(i-1)/2,a[i]);
		            k=a[i];
		      }
		      else
		      {
		            if(space) putchar(' ');
		            space=1;
		            printf("%d %d",i/2,a[i]);
		            k=a[i];
		      }
		}
	}
	printf("\n");
	return 0;
}
