#include <stdio.h>

/*problem id-10375
 *
 *language-ANSI C
 *
 */

int a[20000],b[20000];

int main()
{
	int i,j,k,l,m,n,t,x,y,p,q,r,s,blank,test=0;
	double ans;
	while(scanf("%d %d %d %d",&p,&q,&r,&s)!=EOF)
	{
		for(x=0,i=q+1;i<=p;i++) a[x++]=i;
		for(i=2,t=r-s;i<=t;i++) a[x++]=i;
		for(y=0,i=s+1;i<=r;i++) b[y++]=i;
		for(i=2,t=p-q;i<=t;i++) b[y++]=i;
		for(i=j=0,ans=1;i<x && j<y;)
		{
		      while(i<x && ans<100000) ans*=a[i++];
		      while(j<y && ans>.00009) ans/=b[j++];
		}
		if(j<y) while(j<y) ans/=b[j++];
            else if(i<x) while(i<x) ans*=a[i++];
		printf("%.5lf\n",ans);
	}
	return 0;
}
