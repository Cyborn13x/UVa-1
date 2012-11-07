#include <stdio.h>

/*problem id-11942
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,blank=0,test=0,a[10];
	scanf("%d",&t);
	printf("Lumberjacks:\n");
	while(t--)
	{
		for(i=0;i<10;i++) scanf("%d",&a[i]);
            for(i=2, x=y=a[1]>a[0];i<10 && x==y;i++) y=a[i]>a[i-1];
            printf("%s\n",x==y ? "Ordered" : "Unordered");
	}
	return 0;
}
