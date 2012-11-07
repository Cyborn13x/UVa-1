#include <stdio.h>

/*problem id-10137
 *
 *language-ANSI C
 *
 */

int main()
{
	int i,j,k,l,m,n,t,x,y,blank;
	double a[1000],total,a1,a2;
	char tmp[20];
	while(scanf("%d",&n) && n)
	{
		for(i=total=0;i<n;i++) {scanf("%lf",&a[i]); total+=a[i];}
		total/=n;
		sprintf(tmp,"%.2lf",total);
		sscanf(tmp,"%lf",&total);
		for(i=a1=a2=0;i<n;i++)
		{
			if(a[i]<total) a1+=(total-a[i]);
			else a2+=(a[i]-total);
		}
		printf("$%.2lf\n",a1<a2 ? a1 : a2);
	}
	return 0;
}
