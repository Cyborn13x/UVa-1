#include <stdio.h>
#include <stdlib.h>

/*problem id-10041
 *
 *language-ANSI C
 *
 */

int cmp(const void *a,const void *b) { return *(int *)a-*(int *)b; }

int abs(int a) { return a<0 ? -a :a; }

int main()
{
	int i;
	int m;
	int n;
	int t;
	int x;
	int a[502];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		qsort(a,n,sizeof(int),&cmp);
		m=a[n/2];
		for(i=x=0;i<n;i++) x+= abs(m-a[i]);
		printf("%d\n",x);
	}
	return 0;
}
